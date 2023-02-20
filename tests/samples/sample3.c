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
  uint32_t res = 0;
  for (int i=0; i<4; i++) {
    res += ((uint8_t *)&input)[i] ^ 0xaa;
  }
  return res;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    unsigned long input = strtoul(argv[1], 0, 10);
    uint32_t output = SECRET(input);

    printf("%u\n", output);

    return 0;
}
