#include<stdio.h>
#include<assert.h>
#include<limits.h>

int mult17(int x){
    return (x<<4)+x;
}

int mult_7(int x){
    return -(x<<3)+x;
}

int mult60(int x){
    return (x<<6)-(x<<2);
}

int mult_112(int x){
    return -(x<<7)+(x<<4);
}

int mult63(int x){
    printf("x:         %.8x\n",x);
    printf("x<<6:      %.8x\n",x<<6);
    printf("x<<6-x:    %.8x\n",(x<<6)-x);
    printf("x*63:      %.8x\n",x*63);
    printf("x*63shift: %.8x\n",(x<<5)+(x<<4)+(x<<3)+(x<<2)+(x<<1)+x);
    return (x<<6)-x;
}

/* 原本担心mult63先右移6位，造成了溢出，会导致结果不对，
 * 应该这么看，若右移6位溢出，那么x*63就等于-x;
 * 若乘以y分解成两个右移结果相减: x<<m-x<<n,
 * 2^m>y>2^(m-1),右移m位会溢出，证明乘以y也肯定会溢出;
*/

int main(void){
    int x;
    x=100;
    assert(mult17(x)==(x*17));
    assert(mult_7(x)==(x*-7));
    assert(mult60(x)==(x*60));
    assert(mult_112(x)==(x*-112));
    x=(INT_MAX>>5)+1;
    assert(mult17(x)==(x*17));
    assert(mult_7(x)==(x*-7));
    assert(mult60(x)==(x*60));
    assert(mult_112(x)==(x*-112));
    x=(INT_MIN>>6)-1;
    assert(mult17(x)==(x*17));
    assert(mult_7(x)==(x*-7));
    assert(mult60(x)==(x*60));
    assert(mult_112(x)==(x*-112));
    x=(INT_MAX>>5)+1;
    assert(mult63(x)==(x*63));
}
