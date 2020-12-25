#include<stdio.h>
#include<limits.h>
#include<assert.h>

/* Determine whether arguments can be substracted without overflow */
int tsub_ok(int x, int y){
    int sm = INT_MIN;
    int sub = x-y;
    int pos_over = (!(x&sm)&&(y&sm)&&(sub&sm));
    int neg_over = (x&sm)&&(!(y&sm))&&(!(sub&sm));
    return pos_over||neg_over;
}

int main(void){
    assert(0 == tsub_ok(12345,12344));
    assert(1 == tsub_ok(0,INT_MIN));
    assert(1 == tsub_ok(INT_MIN,1));
    assert(0 == tsub_ok(INT_MIN+1,1));
}
