import sys,re
unit,func,body=sys.argv[1:4]
path=f'src/main/{unit}.cpp'
s=open(path).read()
line=f'INCLUDE_ASM("asm/main/nonmatchings/{unit}", {func});'
assert line in s, line
b=open(body).read().rstrip('\n')
s=s.replace(line,b)
open(path,'w').write(s)
print('landed',func)
