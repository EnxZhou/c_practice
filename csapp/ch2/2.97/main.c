#include<stdio.h>
#include<math.h>
#include "floatcom.h"

/* 辅助学习网站：
 * babbage.cs.qc.cuny.edu/IEEE-754.old/Decimal.html */
unsigned my_abs(int x) {
    unsigned ux;
    if (x<0) {
        ux = (unsigned)(~(x-1));
    }else {
        ux = (unsigned)x;
    }
    return ux;
}

int bit_length(int x) {
    int length = 0;
    if (x==0x80000000) {
        return 32;
    }
    unsigned ux = my_abs(x);
    while(ux!=0){
        ux=ux>>1;
        length++;
    }
    return length;
}

/* 返回i位1bit，例如i=3，返回0x00000007 */
unsigned bits_mask(int i){
    return (unsigned) -1 >> (32-i);
}

/* Compute (float) i */
float_bits float_i2f(int i){
    int length = bit_length(i);
    int fbits = length-1;
    int is_pos = !(i&0x80000000);
    unsigned sign;
    unsigned exp;
    unsigned frac;
    unsigned exp_frac;
    unsigned addition;
    if (is_pos) {
        sign =0;
    }else{
        sign =1;
    }

    exp = fbits+127;
    if (fbits == 31){
        frac = 0x0;
        exp_frac = (exp<<23) | frac;
    }else if(fbits == -1){
        frac = 0x0;
        exp_frac = 0x0;
    }else if(fbits>=23){
        /*
         * （float) int 采用的是round to even，
         * 但要注意，0.11 round to even 则是1.0，
         * 因为0.11大于0.1，只有0.1才需要判断前面一位是否为even
         */
        frac = (my_abs(i)>>(fbits-23))&0x7FFFFF;
        unsigned round_mid = 1<<(fbits-24);
        unsigned round_part = my_abs(i)&bits_mask(fbits-23);
        if (round_mid>round_part){
            addition = 0;
        }else if (round_mid<round_part){
            addition = 1;
        }else{// round_mid == round_part, round to even
            addition = (frac&0x1)==0x1;
        }
        exp_frac = ((exp<<23) | frac)+addition;
    }else{
        frac = (my_abs(i)<<(23-fbits))&0x7FFFFF;
        exp_frac = ((exp<<23) | frac);
    }
    return (sign<<31) | exp_frac;
}

float float_i2f_i(int i) {
    return (float) i;
}
int main(void) {
    //printf("fb:%.8x\n",float_i2f(0x0));
    testFunI2f(float_i2f,float_i2f_i);
    return 0;
}
