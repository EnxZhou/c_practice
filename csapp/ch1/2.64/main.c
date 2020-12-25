#include<stdio.h>
/* Return 1 when any odd bit of x equals 1; 0 otherwise.
 * Assume w=32 */
int any_odd_one(unsigned x){
    return !!(x & 0xAAAAAAAA);
}

/* the odd or even bit count from most significant bit.
 * example: 0x80000000, the most left bit is 1,
 * so the first odd bit is 1.*/
int main(void){
    unsigned x;
    x = 0x80000000;
    printf("check %.8x any odd bit: %d\n",x,any_odd_one(x));
    x = 0x40000000;
    printf("check %.8x any odd bit: %d\n",x,any_odd_one(x));
    x = 0xAAAAAAAA;
    printf("check %.8x any odd bit: %d\n",x,any_odd_one(x));
    x = 0x00000001;
    printf("check %.8x any odd bit: %d\n",x,any_odd_one(x));
    x = 0x8000a000;
    printf("check %.8x any odd bit: %d\n",x,any_odd_one(x));
}
