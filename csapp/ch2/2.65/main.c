#include<stdio.h>

/* Return 1 when x contains an odd number of 1s; 0 therwise.
 * Assume w=32 */
int odd_ones(unsigned x){
    x = x ^ (x>>16);
    x = x ^ (x>>8);
    x = x ^ (x>>4);
    x = x ^ (x>>2);
    x = x ^ (x>>1);
    return x & 0x00000001;
}

int main(void){
    unsigned x;
    x=0x01010101;
    printf("the odd ones result of %.8x is: %d\n",x,odd_ones(x));
    x=0xf1f10101;
    printf("the odd ones result of %.8x is: %d\n",x,odd_ones(x));
    x=0x01010a01;
    printf("the odd ones result of %.8x is: %d\n",x,odd_ones(x));
    x=0x00000000;
    printf("the odd ones result of %.8x is: %d\n",x,odd_ones(x));
    return 0;
}
