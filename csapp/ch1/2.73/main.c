#include<stdio.h>
#include<limits.h>
#include<assert.h>

/* Addition that saturates to TMin or TMax */
int saturating_add(int x, int y){
    int sum = x+y;
    /*sm is short for sign_mask*/
    int sm = INT_MIN;
    int pos_over = ((x+y)&sm)&&(!(x&sm))&&(!(y&sm));
    int neg_over = (!((x+y)&sm))&&(x&sm)&&(y&sm);
    printf("pos_over: %d\n",pos_over);
    printf("neg_over: %d\n",neg_over);
    (pos_over&&(sum=INT_MAX))||
        (neg_over&&(sum=INT_MIN));
    printf("sum: %.8x\n\n",sum);
    return sum;
}

int main(void){
    assert((INT_MAX-1) == saturating_add(0x7fff0000,0x0000fffe));
    assert(INT_MAX == saturating_add(0x7fff0000,0x00010000));
    assert(0x00003333 == saturating_add(0x00001111,0x00002222));
    assert(INT_MIN == saturating_add(0x8fff0000,0x80001111));
    return 0;
}
