#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<assert.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i=0;i<len;i++)
        printf("%.2x",start[i]);
    printf("\n");
}

void show_float(float x) {
    show_bytes((byte_pointer) &x,sizeof(float));
}

unsigned f2u(float x) {
    return *(unsigned*) &x;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);

    show_float(y);
    printf("uy = %.8x\n",uy);
    /* Get the sign bits */
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    /* Give an expression using only ux, uy, sx, and sy */
    return (sx&&sy&&ux>=uy)||(!sx&&!sy&&ux<=uy)||(sx&&!sy)||(ux<<1==0&&uy<<1==0);
}

int main(void) {
    /* dreamanddead CSAPP-3e-Solutions的测试写的不对，负零不会用“-0”表示*/
    int x =INT_MIN;
    float nzero = *(float*) &x;
    assert(float_le(nzero,0));
    assert(float_le(0,nzero));
    assert(float_le(0,3));
    assert(float_le(-4,nzero));
    assert(float_le(-4,4));
}
