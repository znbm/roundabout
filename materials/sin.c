#include <stdio.h>
#include <stdint.h>

typedef int32_t q1_31;
typedef int64_t q1_63;

const q1_31 coef[] = {0x00000fcc, 0x0c849b0a, 0x01938e81, -0x64ff1f88, 0x5980ea22};


q1_31 fixed_mul(q1_31 a, q1_31 b) {
    q1_63 res = (q1_63)a * (q1_63)b;
    return res / (1L << 31);
}

q1_31 fixed_sin(q1_31 a) {
    q1_31 a_pow2 = fixed_mul(a, a);
    q1_31 a_pow3 = fixed_mul(a_pow2, a);
    q1_31 a_pow4 = fixed_mul(a_pow2, a_pow2);

    q1_31 val = coef[0];
    val += fixed_mul(coef[1], a);
    val += fixed_mul(coef[2], a_pow2);
    val += fixed_mul(coef[3], a_pow3);
    val += fixed_mul(coef[4], a_pow4);
    return val << 6;
}

int main() {
    for(int i = 0; i <= (1 << 29); i += (1 << 25)) {
        printf("%.4f\t%.6f\n", -((double)i) / (1 << 31), -((double) fixed_sin(i)) / (1<<31));
    }
    return 0;
}