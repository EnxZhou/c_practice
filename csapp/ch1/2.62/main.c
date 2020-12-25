#include<stdio.h>

unsigned int_shifts_are_arithmetic(){
    return (-1>>1)==-1;
}

int main(void){
    printf("%d\n",int_shifts_are_arithmetic());
}
