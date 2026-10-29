// Adds a file as an overlay block, for an overlay KoudelkaOverlays.java (the import pre-script) did not load.
// Args: block name, hex load address, file. Example (the BIM.AR shared base, config/bim_base.yaml):
//   BIMBASE 800D5DAC C:/Users/jamie/Documents/Koudelka/extracted/bim/bim_base.bin
// Does nothing if the block exists. Run KoudelkaSeedFunctions and KoudelkaFixRefs afterwards, then save.
//@category Koudelka
import java.io.File;
import java.io.FileInputStream;

import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.mem.MemoryBlock;

public class KoudelkaAddOverlay extends GhidraScript {
	@Override
	protected void run() throws Exception {
		String[] a = getScriptArgs();
		if (currentProgram.getMemory().getBlock(a[0]) != null) {
			println("KoudelkaAddOverlay: " + a[0] + " exists");
			return;
		}
		File f = new File(a[2]);
		Address at = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(Long.parseLong(a[1], 16));
		try (FileInputStream in = new FileInputStream(f)) {
			MemoryBlock b = currentProgram.getMemory().createInitializedBlock(a[0], at, in, f.length(), monitor, true);
			b.setRead(true);
			b.setWrite(true);
			b.setExecute(true);
			b.setComment(f.getName());
		}
		println(String.format("KoudelkaAddOverlay: %s at %s, %d bytes", a[0], at, f.length()));
	}
}
