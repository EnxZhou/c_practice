#include<stdio.h>
#include<math.h>
#include<limits.h>
#include "floatcom.h"

/* Compute (int) f.
 * If conversion causes overflow or f is NaN,return 0x80000000
 */
int float_f2i(float_bits f){
    if (is_nan(f)) {
        return 0x80000000;
    }
    if (is_inf(f)) {
        return 0x80000000;
    }
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    unsigned ure;
    if (exp < 127) {
        ure = 0x0;
    }else if (exp <=150) {
        unsigned epb = exp -127;
        ure = 1 << epb | frac >> (23-epb);
    }else if(exp<=157){
        unsigned epb = exp -127;
        ure = 1 << epb | frac << (epb-23);
    }else{
        return 0x80000000;
    }

    if (sign){
        return ~ure+1;
    }else {
        return ure;
    }
}

int float_f2i_f(float f) {
    return (int)f;
}
int main(void) {
    testFunInt(float_f2i,float_f2i_f);
    return 0;
}
