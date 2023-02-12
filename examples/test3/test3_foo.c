
#ifdef ENABLE_OLLVM
__attribute((__annotate__(("fla"))))
__attribute((__annotate__(("bcf"))))
#endif
#ifdef ENABLE_XVMP
__attribute((__annotate__(("vmp"))))
#endif
int foo(int a, int b) {
    return a+b;
}
