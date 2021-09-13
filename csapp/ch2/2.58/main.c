#include<stdio.h>
#include<string.h>

int is_little_endian(){
    unsigned a = 1;
    unsigned char *b = (unsigned char *) &a;
    return b[0];
}

int main(){
    printf("this computer is littel endian: %d\n",is_little_endian());
    return 0;
}
