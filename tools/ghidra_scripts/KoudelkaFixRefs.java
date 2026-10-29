// Fixes references that cross address spaces, from the facts tools/ghidra_pointer_list.py writes (arg 0, or asked).
// Five overlays share 0x800B6DF0 and EFFECT loads right after BATTLE, so Ghidra resolves any address in that range
// to the empty default RAM block. This
//  1. retargets references into that block: BATTLE -> EFFECT above 0x800D5DAC, EFFECT -> BATTLE below it, and an
//     EXE reference to the one overlay with a label at that address (left alone when several have one);
//  2. marks every pointer word splat knows (`.word sym` in data) as a pointer to the right space, but only where
//     the bytes are undefined or already a pointer: it never overwrites code or a type someone set;
//  3. removes the functions Ghidra made in the RAM block once nothing refers to them.
// Run with GhydraMCP's scripts_run or from the Script Manager, then save.
//@category Koudelka
import java.io.File;
import java.nio.file.Files;
import java.util.*;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.PointerDataType;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;

public class KoudelkaFixRefs extends GhidraScript {
	static final long SLOT = 0x800B6DF0L, EFFECT_BASE = 0x800D5DACL;

	AddressSpace space(String name) {
		return name.equals("ram") ? currentProgram.getAddressFactory().getDefaultAddressSpace()
			: currentProgram.getAddressFactory().getAddressSpace(name);
	}

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		File list = args.length > 0 ? new File(args[0]) : askFile("tools/ghidra_pointer_list.py output", "Fix");
		Map<Long, List<String>> labelSpaces = new HashMap<>();
		List<String[]> ptrs = new ArrayList<>();
		for (String line : Files.readAllLines(list.toPath())) {
			String[] f = line.trim().split("\\s+");
			if (f[0].equals("label")) {
				labelSpaces.computeIfAbsent(Long.parseLong(f[2], 16), k -> new ArrayList<>()).add(f[1]);
			} else if (f[0].equals("ptr")) {
				ptrs.add(f);
			}
		}
		ReferenceManager rm = currentProgram.getReferenceManager();
		Listing listing = currentProgram.getListing();
		AddressSpace ram = space("ram");

		// 1. References into the default RAM block's overlay range.
		int moved = 0, ambiguous = 0;
		AddressSet slot = new AddressSet(ram.getAddress(SLOT), ram.getAddress(0x801FFFFFL));
		List<Reference> bad = new ArrayList<>();
		for (Address to : rm.getReferenceDestinationIterator(slot, true)) {
			ReferenceIterator it = rm.getReferencesTo(to);
			while (it.hasNext()) {
				bad.add(it.next());
			}
		}
		for (Reference r : bad) {
			Address from = r.getFromAddress();
			long x = r.getToAddress().getOffset();
			MemoryBlock src = currentProgram.getMemory().getBlock(from);
			String srcName = src == null ? null : src.isOverlay() ? src.getName() : "ram";
			String dst = null;
			if ("BATTLE".equals(srcName) && x >= EFFECT_BASE) {
				dst = "EFFECT";
			} else if ("EFFECT".equals(srcName) && x < EFFECT_BASE) {
				dst = "BATTLE";
			} else if ("ram".equals(srcName)) {
				List<String> c = labelSpaces.getOrDefault(x, Collections.emptyList());
				if (c.size() == 1) {
					dst = c.get(0);
				} else if (c.size() > 1) {
					ambiguous++;
				}
			}
			if (dst == null) {
				continue;
			}
			Address to = space(dst).getAddress(x);
			rm.delete(r);
			Reference n = rm.addMemoryReference(from, to, r.getReferenceType(), SourceType.ANALYSIS, r.getOperandIndex());
			if (r.isPrimary()) {
				rm.setPrimary(n, true);
			}
			moved++;
		}

		// 2. Pointer words.
		int created = 0, retargeted = 0, skipped = 0;
		for (String[] f : ptrs) {
			Address at = space(f[1]).getAddress(Long.parseLong(f[2], 16));
			Address to = space(f[3]).getAddress(Long.parseLong(f[4], 16));
			if (listing.getInstructionContaining(at) != null) {
				skipped++;
				continue;
			}
			Data d = listing.getDataAt(at);
			Data containing = listing.getDataContaining(at);
			if (d == null || !d.getAddress().equals(at) || (containing != null && containing != d)) {
				skipped++;  // inside a larger structure or array someone defined
				continue;
			}
			if (!d.isPointer()) {
				if (d.isDefined()) {
					skipped++;
					continue;
				}
				try {
					listing.createData(at, PointerDataType.dataType);
					created++;
				} catch (Exception e) {
					skipped++;
					continue;
				}
			}
			boolean right = false;
			for (Reference r : rm.getReferencesFrom(at)) {
				if (r.getToAddress().equals(to)) {
					right = true;
				} else {
					rm.delete(r);
				}
			}
			if (!right) {
				Reference n = rm.addMemoryReference(at, to, RefType.DATA, SourceType.ANALYSIS, 0);
				rm.setPrimary(n, true);
				retargeted++;
			}
		}

		// 3. Functions left in the default RAM block with nothing referring to them.
		int removed = 0, kept = 0;
		FunctionIterator fi = currentProgram.getFunctionManager().getFunctions(slot, true);
		List<Function> dead = new ArrayList<>();
		while (fi.hasNext()) {
			Function fn = fi.next();
			if (rm.getReferenceCountTo(fn.getEntryPoint()) == 0) {
				dead.add(fn);
			} else {
				kept++;
			}
		}
		for (Function fn : dead) {
			currentProgram.getFunctionManager().removeFunction(fn.getEntryPoint());
			removed++;
		}
		println(String.format("KoudelkaFixRefs: references moved %d (EXE refs left ambiguous %d); pointers created %d, "
			+ "pointed right %d, skipped %d; RAM-block functions removed %d, still referenced %d",
			moved, ambiguous, created, retargeted, skipped, removed, kept));
	}
}
