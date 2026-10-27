// Writes every function as "block,address,size,name" to the CSV given as arg 0.
// Run headless with -process <program> -noanalysis -readOnly -postScript.
//@category Koudelka
import java.io.PrintWriter;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.mem.MemoryBlock;

public class ExportFunctions extends GhidraScript {
	@Override
	protected void run() throws Exception {
		try (PrintWriter out = new PrintWriter(getScriptArgs()[0])) {
			out.println("block,address,size,name");
			for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
				MemoryBlock b = currentProgram.getMemory().getBlock(f.getEntryPoint());
				out.printf("%s,%08x,%d,%s%n", b == null ? "?" : b.getName(),
					f.getEntryPoint().getOffset(), f.getBody().getNumAddresses(), f.getName());
			}
		}
	}
}
