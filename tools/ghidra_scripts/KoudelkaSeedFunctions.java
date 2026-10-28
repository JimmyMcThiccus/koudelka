// Creates every function splat knows about, and gives Ghidra's default-named ones our names.
// Arg 0 (or asked for when run from the Script Manager): the list from tools/ghidra_function_list.py,
// lines "<space> <hex address> <name>", space "ram" for the EXE, else the overlay block (FIELD, ...).
// Ghidra's own analysis finds far fewer functions than splat (FIELD: 362 of 745); with these seeded,
// the decompiler works on any address, and its output calls functions by the names our source uses.
// Names a user has set in Ghidra are left alone.
//@category Koudelka
import java.io.File;
import java.nio.file.Files;

import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

public class KoudelkaSeedFunctions extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] args = getScriptArgs();
		File list = args.length > 0 ? new File(args[0])
			: askFile("Function list (tools/ghidra_function_list.py)", "Seed");
		int created = 0, renamed = 0, failed = 0;
		for (String line : Files.readAllLines(list.toPath())) {
			String[] f = line.trim().split("\\s+");
			if (f.length < 3) {
				continue;
			}
			AddressSpace space = f[0].equals("ram") ? currentProgram.getAddressFactory().getDefaultAddressSpace()
				: currentProgram.getAddressFactory().getAddressSpace(f[0]);
			if (space == null) {
				printerr("no address space " + f[0]);
				failed++;
				continue;
			}
			Address a = space.getAddress(Long.parseLong(f[1], 16));
			Function fn = getFunctionAt(a);
			if (fn == null) {
				if (getInstructionAt(a) == null) {
					new DisassembleCommand(a, null, true).applyTo(currentProgram, monitor);
				}
				new CreateFunctionCmd(a).applyTo(currentProgram, monitor);
				fn = getFunctionAt(a);
				if (fn == null) {
					printerr("could not create " + f[2] + " at " + a);
					failed++;
					continue;
				}
				created++;
			}
			if (fn.getSymbol().getSource() == SourceType.DEFAULT && !fn.getName().equals(f[2])) {
				fn.setName(f[2], SourceType.IMPORTED);
				renamed++;
			}
		}
		println(String.format("KoudelkaSeedFunctions: %d created, %d renamed, %d failed", created, renamed, failed));
	}
}
