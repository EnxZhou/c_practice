#include<stdio.h>
#include<math.h>
#include "floatcom.h"

float_bits float_absval(float_bits f){
    if (is_nan(f)) {
        return f;
    }
    return f & 0x7FFFFFFF;
}

float float_absval_f(float f) {
    if(isnan(f)) return f;
    return fabs(f);
}
/* Compute |f|. If f is NaN, then return f. */
int main(void) {
    testFun(float_absval,float_absval_f);
    return 0;
}
