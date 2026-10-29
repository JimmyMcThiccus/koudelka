hdr='''struct Unk_800CC85C_s { short x, y; };
struct Unk_800CC85C : Unk_Ft4_10 { char pad_[0x60 - 0x10 - sizeof(POLY_FT4)]; unsigned char ox, oy; };
//--
EXTERN_C void func_800CC85C(Unk_800CC85C* p, Unk_800CC85C_s* s) {
    int i = D_800B4CF0[0];
    int x = s->x, y = s->y;
    int ox = p->ox, oy = p->oy;
'''
st={'u0':'p->unk10[i].u0 = *(unsigned char*)s + p->ox;','v0':'p->unk10[i].v0 = ((unsigned char*)s)[2] + p->oy;',
'dx':'int dx = x + ox - p->unk10[i].x0;','dy':'int dy = y + oy - p->unk10[i].y0;',
'u1':'p->unk10[i].u1 = p->unk10[i].x1 + dx;','u2':'p->unk10[i].u2 = p->unk10[i].u0;','u3':'p->unk10[i].u3 = p->unk10[i].x3 + dx;',
'v1':'p->unk10[i].v1 = p->unk10[i].v0;','v2':'p->unk10[i].v2 = p->unk10[i].y2 + dy;','v3':'p->unk10[i].v3 = p->unk10[i].y3 + dy;'}
orders=[
['u0','v0','dx','dy','u2','u1','u3','v2','v1','v3'],
['u0','v0','dx','dy','u1','u2','u3','v1','v2','v3'],
['u0','v0','dx','dy','u1','v1','u2','v2','u3','v3'],
['dx','dy','u0','v0','u1','u2','u3','v1','v2','v3'],
]
out=''
for n,o in enumerate(orders):
    out+='### func_800CC85C@%d\n'%(20+n)+hdr+'\n'.join('    '+st[k] for k in o)+'\n    func_8005F1D8(p);\n}\n'
open('scratch_c/hb_3.txt','w').write(out)
