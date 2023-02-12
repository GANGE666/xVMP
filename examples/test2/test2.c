#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void tea_encrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0, i;           /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i < 32; i++) {                       /* basic cycle start */
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}

#ifdef ENABLE_OLLVM
__attribute((__annotate__(("fla"))))
__attribute((__annotate__(("bcf"))))
#endif
#ifdef ENABLE_XVMP
__attribute((__annotate__(("vmp"))))
#endif
uint32_t tea_decrypt (uint32_t* v) {
    // uint32_t* v = &input;
    uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;  /* set up */
    uint32_t delta=0x9e3779b9;                     /* a key schedule constant */
    uint32_t k0=0x94C36D33, k1=0x164512A3, k2=0xFEEEDA59, k3=0x87BD19BD;   /* cache key */
    for (i=0; i<32; i++) {                         /* basic cycle start */
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
    return v[0];
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Call this program with 1 arguments\n");
        return 1;
    }

    unsigned long input = strtoul(argv[1], 0, 10);
    uint32_t v[2] = {0};
    v[0] = input & 0xFFFFFFFF;
    v[1] = 0;

    // uint32_t output = SECRET(input);
    uint32_t output = tea_decrypt(v);

    printf("%u\n", output);

    return 0;
}

