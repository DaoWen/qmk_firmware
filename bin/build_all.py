import subprocess
import os
import sys

BOARDS = [
    'gmmk/full/rev2',
    'gmmk/full/rev3',
    'gmmk/tkl/rev2',
    'gmmk/tkl/rev3']

error = False
for kb in BOARDS:
    if subprocess.run(f"qmk compile -kb {kb} -km all -j{os.cpu_count()}", shell=True).returncode != 0:
        error = True
if error:
    sys.exit(1)
