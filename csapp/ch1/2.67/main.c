#include<stdio.h>

int int_size_is_32(){
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 <<31;
    /* Shift past msb of 32-bit word */
    int beyond_msb =set_msb<<1;
    return set_msb && !beyond_msb;
}

int int_size_is_32_for_16(){
    /* Set most significant bit (msb) of 32-bit machine */
    int set_msb = 1 <<15;
    set_msb<<=15;
    set_msb<<=1;
    /* Shift past msb of 32-bit word */
    int beyond_msb =set_msb<<1;
    return set_msb && !beyond_msb;
}

int main(void){
    printf("%d\n",int_size_is_32());
    printf("%d\n",int_size_is_32_for_16());
    return 0;
}
