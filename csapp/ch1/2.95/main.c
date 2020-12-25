#include<stdio.h>
#include<math.h>
#include "floatcom.h"

float_bits float_half(float_bits f){
    if (is_nan(f)) {
        return f;
    }
    if (is_inf(f)) {
        return f;
    }
    unsigned sign = f>>31;
    unsigned exp = f>>23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;
    /*
     * 这里只需要舍去一位，所以可以仅根据最后两位来确定addition
     * 如要舍去多位，则要考虑舍去的数字是否大于round middle，
     * 参考2.97题。
     */
    unsigned addition = (f&0x3)==0x3;
    if (exp == 0) {
        return sign<<31 | ((frac >> 1) + addition);
    }else if (exp==1) {
        return sign<<31 | (((f & 0xFFFFFF) >> 1) + addition);
    }
    return sign<<31 | (exp-1)<<23 | frac;
}

float float_half_f(float f) {
    if(isnan(f)) return f;
    return (float)0.5*f;
}
/* Compute 0.5*f. If f is NaN, then return f. */
int main(void) {
    testFun(float_half,float_half_f);
    return 0;
}
