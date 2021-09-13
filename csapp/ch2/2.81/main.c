#include<stdio.h>
#include<limits.h>
#include<assert.h>

/* 1^(w-k)0^k */
int question_a(int k){
    return (-1)<<k;
}

/* 0^(w-k-j)1^k0^j */
int question_b(int j,int k){
    return ((1<<k)-1)<<j;
}

int main(void) {
    assert(question_a(8) == 0xffffff00);
    assert(question_b(8,16) == 0x00ffff00);
    return 0;
}
