// Adds Koudelka's code overlays (BIN/*.BIN) as Ghidra overlay blocks and
// seeds functions at every in-range jal target, so auto-analysis covers them.
// Run as a headless -preScript after importing SLUS_010.51 with the PSX loader.
// Arg: path to the extracted BIN/ directory.
//@category Koudelka
import java.io.File;
import java.io.FileInputStream;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.file.Files;

import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.mem.MemoryBlock;

public class KoudelkaOverlays extends GhidraScript {

	// name, load address (found from jal-target / prologue alignment)
	private static final Object[][] OVERLAYS = {
		{ "FIELD", 0x800b6df0L },
		{ "BATTLE", 0x800b6df0L },
		{ "MOVIE", 0x800b6df0L },
		{ "CAPTURE", 0x800b6df0L },
		{ "GAMEEND", 0x800b6df0L },
		{ "EFFECT", 0x800d5dacL }, // loads directly after BATTLE
	};

	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		File binDir = new File(args.length > 0 ? args[0] : askDirectory("BIN dir", "OK").getPath());

		// Library signature scoring (tools/psyq_version.py) points to PsyQ 4.6.
		currentProgram.getOptions("Analyzers")
				.setString("PsyQ Signatures.PsyQ Version if not found", "4.6.0");

		// The PSX loader splits the EXE into sections; seed every initialized block of it.
		for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
			long s = b.getStart().getOffset();
			if (b.isInitialized() && !b.isOverlay() && s >= 0x80010000L && s < 0x800b5000L) {
				seed(b.getStart().getAddressSpace(), 0x80010000L, 0xa5000L, b);
			}
		}
		if (args.length > 1 && args[1].equals("main-only")) {
			return;
		}

		for (Object[] ov : OVERLAYS) {
			String name = (String) ov[0];
			long base = (Long) ov[1];
			File f = new File(binDir, name + ".BIN");
			Address start = toAddr(base);
			MemoryBlock blk;
			try (FileInputStream in = new FileInputStream(f)) {
				blk = currentProgram.getMemory().createInitializedBlock(
					name, start, in, f.length(), monitor, true);
			}
			blk.setRead(true);
			blk.setWrite(true);
			blk.setExecute(true);
			blk.setComment("BIN/" + name + ".BIN");
			println(String.format("overlay %s @ %08x size %x", name, base, f.length()));
			seed(blk.getStart().getAddressSpace(), base, f.length(), blk);
		}
	}

	// Scan blk for jal instructions; create functions at targets inside [base, base+size).
	private void seed(AddressSpace space, long base, long size, MemoryBlock blk) throws Exception {
		byte[] data = new byte[(int) blk.getSize()];
		blk.getBytes(blk.getStart(), data);
		ByteBuffer bb = ByteBuffer.wrap(data).order(ByteOrder.LITTLE_ENDIAN);
		int made = 0;
		for (int i = 0; i + 4 <= data.length; i += 4) {
			int w = bb.getInt(i);
			if ((w >>> 26) != 3) {
				continue;
			}
			long t = 0x80000000L | ((long) (w & 0x3ffffff) << 2);
			if (t < base || t >= base + size) {
				continue;
			}
			Address a = space.getAddress(t);
			if (getFunctionAt(a) != null) {
				continue;
			}
			new DisassembleCommand(a, null, true).applyTo(currentProgram, monitor);
			if (createFunction(a, null) != null) {
				made++;
			}
		}
		println(String.format("%s: seeded %d functions", blk.getName(), made));
	}
}
