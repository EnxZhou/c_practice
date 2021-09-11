#include<stdio.h>
/* Mask with least signficant n bits set to 1
 * Examples: n = 6 -->0x3F, n = 17 -->0x1FFFF
 * Assume 1 <= n <=w */
int lower_one_mask(int n){
    return (1<<(n>>1)<<(n-(n>>1)))-1;
}

int main(void){
    int n;
    n = 1;
    printf("when n = %d, result is 0x%x\n",n,lower_one_mask(n));
    n = 6;
    printf("when n = %d, result is 0x%x\n",n,lower_one_mask(n));
    n = 17;
    printf("when n = %d, result is 0x%x\n",n,lower_one_mask(n));
    n = 32;
    printf("when n = %d, result is 0x%x\n",n,lower_one_mask(n));
    n = 0;
    printf("when n = %d, result is 0x%x\n",n,lower_one_mask(n));
    return 0;
}
