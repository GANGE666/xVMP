#include "test3_foo.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    int input = atoi(argv[1]);

    int res = foo(input, 0xdeadbeef);
    printf("%d\n", res);

    return 0;
}

