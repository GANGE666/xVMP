#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char buff[1000];

#ifdef ENABLE_OLLVM
__attribute((__annotate__(("fla"))))
__attribute((__annotate__(("bcf"))))
#endif
#ifdef ENABLE_GOVMP
__attribute((__annotate__(("vmp"))))
#endif
char* SECRET(char* input) {
    printf("%s\n", input);
    for (int idx=0; idx<strlen(input); idx++) {
        input[idx] += 1;
    }
    printf("%s\n", input);
    strcpy(buff, input);
    strcat(buff, " abcdefg");
  return buff;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    // unsigned long input = strtoul(argv[1], 0, 10);
    char* output = SECRET(argv[1]);

    printf("%s\n", output);

    return 0;
}
