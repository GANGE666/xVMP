#include<stdio.h>

#ifdef ENABLE_OLLVM
__attribute((__annotate__(("fla"))))
__attribute((__annotate__(("bcf"))))
#endif
#ifdef ENABLE_XVMP
__attribute((__annotate__(("vmp"))))
#endif
void vm_test(char * buf, int len){
        for(int i = 0; i < len; i++)
                buf[i] ^= 0x3A;
}

int main() {
    char array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vm_test(array, 10);
    
    for (int i=0; i<10; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
}

