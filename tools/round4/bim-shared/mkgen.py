# usage: mkgen.py out.py refmod reffn njals  (body template read from scratch_c/body_<out>.txt using {names[i]} and {fn})
import sys
out,refmod,reffn,nj=sys.argv[1:5]
tmpl=open('scratch_c/gen_template.py').read()
tmpl=tmpl.replace('@@REFMOD@@',refmod).replace('@@REFFN@@',reffn).replace('@@NJ@@',nj).replace('@@OUT@@',out)
open(f'scratch_c/{out}.py','w').write(tmpl)
