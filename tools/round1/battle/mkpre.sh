# prelude for scratch files: battle.h with macros expanded by hand
sed -e '/^#/d' -e 's/LUI_DATA/__attribute__((section(".data")))/' -e 's/EXTERN_C /extern "C" /' /c/Users/jamie/Documents/Koudelka-wt/battle/include/battle/battle.h
