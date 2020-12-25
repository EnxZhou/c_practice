#include<stdio.h>
#include<limits.h>
#include<assert.h>

int divide_power2(int x,int k){
    int is_neg = x&INT_MIN;
    is_neg&&(x=x+(1<<k)-1);
    return x>>k;
}

int mul3div4(int x){
    x=(x<<1)+x;
    x=divide_power2(x,2);
    return x;
}

int main(void){
    int x = 4;
    assert(mul3div4(x)==3);
    x=INT_MIN;
    assert(mul3div4(x)==0xe0000000);
    x=0x87654321;
    assert(mul3div4(x)==x*3/4);
    return 0;
}
