#include<stdio.h>

unsigned replace_byte(unsigned x,int i,unsigned char b){
    unsigned ub = (unsigned) b<<(i*8);
    unsigned mask = ~((0xff)<<(i*8));
    x=(x&mask)|ub;
    return x;
}

int main(void){
    unsigned x = 0x12345678;
    unsigned replace_x_two = replace_byte(x,2,0xAB);
    unsigned replace_x_zero = replace_byte(x,0,0xAB);
    printf("result of replace_byte(x,2,0xAB): %x\n",replace_x_two);
    printf("result of replace_byte(x,0,0xAB): %x\n",replace_x_zero);
}
