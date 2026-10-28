"""run batch, retry sections that fail with 'not found' (asm tree churn)."""
import subprocess, sys, re
args = sys.argv[1:]
for attempt in range(4):
    r = subprocess.run([sys.executable, "scratch_c/battle-batch.py"] + args, capture_output=True, text=True)
    out = r.stdout
    if "not found under" not in out and "No such file" not in out:
        break
print(out)
