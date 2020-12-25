#include<stdio.h>

/* Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example, 0xFF00 -> 0x8000, and 0x6600 ->0x4000.
 * If x = 0, then return 0.
 */
int leftmost_one(unsigned x){
    x = x | x>>1;
    x = x | x>>2;
    x = x | x>>4;
    x = x | x>>8;
    x = x | x>>16;
    return x-(x>>1);
}

int main(void){
    unsigned x;
    x=0x01010101;
    printf("the left most one result of %.8x is: %.8x\n",x,leftmost_one(x));
    x=0x01f10101;
    printf("the left most one result of %.8x is: %.8x\n",x,leftmost_one(x));
    x=0x000a0101;
    printf("the left most one result of %.8x is: %.8x\n",x,leftmost_one(x));
    x=0x00000002;
    printf("the left most one result of %.8x is: %.8x\n",x,leftmost_one(x));
    return 0;
}
