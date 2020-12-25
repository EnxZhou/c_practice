#include<stdio.h>
#include<assert.h>
#include "floatcom.h"

//typedef unsigned float_bits;

float u2f(unsigned x) {
    return *((float*)&x);
}

unsigned f2u(float f) {
    return *((unsigned*)&f);
}

int is_float_equal(float_bits f1,float f2) {
    return f2u(f2) == f1;
}

int is_int_equal(int i1, int i2) {
    return i1==i2;
}

int is_nan(float_bits fb) {
    unsigned exp =fb>>23 & 0xFF;
    unsigned frac = fb & 0x7FFFFF;
    return exp==0xFF&&frac!=0;
}

int is_inf(float_bits fb) {
    unsigned exp =fb>>23 & 0xFF;
    unsigned frac = fb & 0x7FFFFF;
    return exp==0xFF&&frac==0;
}

int testFun(float_bits(*fun1)(float_bits),float(*fun2)(float)) {
    unsigned x = 0;
    do{
        float_bits fb = fun1(x);
        float ff = fun2(u2f(x));
        if(!is_float_equal(fb,ff)) {
            printf("fb:%.8x\n",fb);
            printf("%x error\n",x);
            return 0;
        }
        x++;
    }while(x!=0);
    printf("Tesk ok\n");
    return 0;
}

int testFunInt(int (*fun1)(float_bits),int(*fun2)(float)){
    unsigned x = 0;
    do {
        int fbti = fun1(x);
        int fti = fun2(u2f(x));
        if (!is_int_equal(fbti,fti)){
            printf("fbti: %.8x\n",fbti);
            printf("fti: %.8x\n",fti);
            printf("%x error\n",x);
            return 0;
        }
        x++;
    }while(x!=0);
    printf("Tesk ok\n");
    return 0;
}
