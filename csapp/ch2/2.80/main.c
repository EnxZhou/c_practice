#include<stdio.h>
#include<limits.h>
#include<assert.h>

int divide_power(int x,int k){
    int is_neg = x&INT_MIN;
    is_neg&&(x=x+(1<<k)-1);
    return x>>k;
}

/* round depart zero*/
int divide_power2(int x,int k){
    int is_neg = x&INT_MIN;
    is_neg&&(x=x>>k);
    (!is_neg)&&(x=(x+((1<<k)-1))>>k);
    return x;
}

int threefourths(int x){
    int large_four = x&(INT_MIN>>29);
    printf("x: %.8x  ",x);
    large_four&&(x=x-divide_power2(x,2));
    (!large_four)&&(x=divide_power(x+(x<<1),2));
    printf("x: %.8x\n",x);
    return x;
}

int main(void){
    int x = 3;
    assert(threefourths(x)==2);
    x=INT_MIN;
    assert(threefourths(x)==0xa0000000);
    x=0x87654321;
    assert(threefourths(x)==0xa58bf259);
    x=12345;
    assert(threefourths(x)==9258);
    assert(threefourths(-8)==-6);
    assert(threefourths(-9)==-6);
    assert(threefourths(-10)==-7);
    assert(threefourths(-11)==-8);
    assert(threefourths(-12)==-9);
    assert(threefourths(8)==6);
    assert(threefourths(9)==6);
    assert(threefourths(10)==7);
    assert(threefourths(11)==8);
    assert(threefourths(12)==9);
    return 0;
}
