#include<stdio.h>
#include<assert.h>

/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 therwise
 * Assume 1 <= n <= w
 */

int fite_bits(int x,int n){
    int w = sizeof(int)<<3;
    int y = x << (w-n) >> (w-n);
    return x == y;
}

int main(void){
    assert(!fite_bits(0xff,8));
    assert(!fite_bits(~0xff,8));

    assert(fite_bits(0b0010,3));
    assert(!fite_bits(0b1010,3));
    assert(!fite_bits(0b0110,3));

    assert(fite_bits(0b11,3));
    assert(!fite_bits(0b01000011,3));
    assert(!fite_bits(~0b111,3));
    return 0;
}
