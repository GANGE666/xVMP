# Original
`clang test2.c -o test2`

# xVMP
xvmp:
`clang -DENABLE_XVMP test2.c -o test2_xvmp`

xvmp+ollvm:
`clang -DENABLE_XVMP -DENABLE_OLLVM test2.c -o test2_xvmp_ollvm`

# Tigress
`tigress --Environment=x86_64:Linux:Gcc:4.6 --Seed=0  --Transform=Virtualize   --VirtualizeDispatch=interpolation --Functions=tea_decrypt --VirtualizeEncodeByteArray=true test2.c --out=test2_tigress.c`
`clang test2_tigress.c -o test2_tigress`

