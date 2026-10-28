#!/bin/sh
for f in "$@"; do sed -E 's|^\s*/\* [0-9A-F]+ [0-9A-F]+ [0-9A-F]+ \*/\s*|  |' asm/battle/nonmatchings/battle/$f.s | grep -v '^\s*$'; done
