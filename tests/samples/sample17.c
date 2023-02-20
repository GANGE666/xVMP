#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

uint8_t a[] = {1,2,3,4,5,6,7,8,9,0};

#ifdef ENABLE_GOVMP
__attribute((__annotate__(("vmp"))))
#endif
uint32_t SECRET(unsigned long input) {
  for (int i=0; i<sizeof(a); i++) {
    a[i] = a[i] ^ (uint8_t)input;
  }
  uint32_t res = 0;
  for (int i=0; i<sizeof(a); i++) {
    res += a[i];
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
