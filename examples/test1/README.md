# Original
`clang test1.c -o test1`

# xVMP
xvmp:
`clang -DENABLE_XVMP test1.c -o test1_xvmp`

xvmp+ollvm:
`clang -DENABLE_XVMP -DENABLE_OLLVM test1.c -o test1_xvmp_ollvm`

# Tigress
`tigress --Environment=x86_64:Linux:Gcc:4.6 --Seed=0  --Transform=Virtualize   --VirtualizeDispatch=interpolation --Functions=vm_test --VirtualizeEncodeByteArray=true test1.c --out=test1_tigress.c`
`clang test1_tigress.c -o test1_tigress`

