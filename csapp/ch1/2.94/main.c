#include<stdio.h>
#include<math.h>
#include "floatcom.h"

float_bits float_twice(float_bits f){
    if (is_nan(f)) {
        return f;
    }
    if (is_inf(f)) {
        return f;
    }
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    if (exp == 0) {
        return sign<<31 | frac <<1;
    }else if (exp==0xFF-1) {
        return sign<<31 | 0xFF<<23 | 0x0;
    }
    return sign<<31 | (exp+1)<<23 | frac;
}

float float_twice_f(float f) {
    if(isnan(f)) return f;
    return 2.0*f;
}
/* Compute 2*f. If f is NaN, then return f. */
int main(void) {
    testFun(float_twice,float_twice_f);
    return 0;
}
