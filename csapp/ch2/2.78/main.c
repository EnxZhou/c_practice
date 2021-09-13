#include<stdio.h>
#include<limits.h>

/* Divide by power of 2. Assume 0 <= k <w-1 */
int divide_power2(int x, int k){
    int is_neg = x&INT_MIN;
    int res;
    (is_neg && (x= x+(1<<k)-1));
    res = x>>k;
    return res;
}

int main(void){
    int x =0x80000007;
    printf("%d divide_power2 1: %d\n",x,divide_power2(x,1));
    printf("%d divide_power2 2: %d\n",x,divide_power2(x,2));
    printf("%d divide_power2 3: %d\n",x,divide_power2(x,3));
    printf("%d divide_power2 4: %d\n",x,divide_power2(x,4));
    return 0;
}
