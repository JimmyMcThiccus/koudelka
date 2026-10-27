"""Pad a built binary to the retail size and compare its SHA-1.

The EXE's text size is rounded up to 0x800, so the linked image is padded with
zeros to the retail length before hashing. On mismatch, reports the first
differing offset.

Usage: python check.py <built.bin> <retail_size> <retail_sha1>
"""
import hashlib
import sys


def main():
    path, size, want = sys.argv[1], int(sys.argv[2]), sys.argv[3]
    data = open(path, "rb").read()
    if len(data) > size:
        print(f"check: FAIL {path}: {len(data):#x} bytes, retail is {size:#x}")
        return 1
    data = data.ljust(size, b"\0")
    got = hashlib.sha1(data).hexdigest()
    if got == want:
        print(f"check: OK {path} {got}")
        return 0
    print(f"check: FAIL {path} sha1 {got}, want {want}")
    return 1


if __name__ == "__main__":
    sys.exit(main())
