#include<stdio.h>
#include<assert.h>

/* do rotating left shift. Assume 0 <= n <w
 * Examples when x = 0x12345678 and w =32:
 *   n=4 ->0x2345671, n=20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n){
    unsigned w = 32;
    /* the shift count can not large 31, the reason like question 2.67 */
    unsigned left = x>>(w-n-1)>>1;
    unsigned right = x<<n;
    return left | right;
}

int main(void){
    unsigned x;
    x = 0x12345678;
    assert(rotate_left(x,4) == 0x23456781);
    assert(rotate_left(x,0) == 0x12345678);
    assert(rotate_left(x,20) == 0x67812345);
    return 0;
}
