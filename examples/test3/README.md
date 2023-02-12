# Original
`clang test3_main.c test3_foo.c -o test3`

# xVMP
xvmp:
`clang -DENABLE_XVMP test3_main.c test3_foo.c -o test3_xvmp`

xvmp+ollvm:
`clang -DENABLE_XVMP -DENABLE_OLLVM test3_main.c test3_foo.c -o test3_xvmp_ollvm`

# Tigress
Because Tigress can only accept a whole program single C file as input, which means that the original compilation process needs to be broken and is very unfriendly to developers.
And you need merge all C file into one as following.
`tigress-merge test3_main.c test3_foo.c --out=test3_tigress.c`
`tigress --Environment=x86_64:Linux:Gcc:4.6 --Seed=0  --Transform=Virtualize   --VirtualizeDispatch=interpolation --Functions=foo --VirtualizeEncodeByteArray=true test3_tigress.c --out=test3_tigress_obf.c`
`clang test3_tigress_obf.c -o test3_tigress_obf`

If you directly obfuscate `test3_foo.c` by Tigress, a new `main` function will be introduced in the output file of `test_foo.c`.


