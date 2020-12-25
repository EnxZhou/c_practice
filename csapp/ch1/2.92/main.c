#include<stdio.h>
#include<math.h>
#include "floatcom.h"

float_bits float_negate(float_bits f){
    unsigned sign = f>>31;
    if (is_nan(f)) {
        return f;
    }
    return ((!sign)<<31) | (f&0x7FFFFFFF);
}

float float_negate_f(float f) {
    if(isnan(f)) return f;
    return -f;
}
/* Compute -f. If f is NaN, then return f. */
int main(void) {
    testFun(float_negate,float_negate_f);
    return 0;
}
