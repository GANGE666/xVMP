#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef ENABLE_OLLVM
__attribute((__annotate__(("fla"))))
__attribute((__annotate__(("bcf"))))
#endif
#ifdef ENABLE_GOVMP
__attribute((__annotate__(("vmp"))))
#endif
uint32_t SECRET(unsigned long input) {
  return input ^ 0xdeadbeef;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    unsigned long input = strtoul(argv[1], 0, 10);
    uint32_t output = SECRET(input);

    printf("0x%x\n", output);

    return 0;
}
