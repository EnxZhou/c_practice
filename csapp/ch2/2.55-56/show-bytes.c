#include<stdio.h>
#include<string.h>
#include<limits.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start,size_t len) {
    size_t i;
    for (i=0;i<len;i++)
        printf("%.2x",start[i]);
    printf("\n");
}

int main(){
    int ia = 1;
    int ina = -1;
    unsigned ua = 1;
    long la =1;
    float fa = 1.0;

    byte_pointer ib = (byte_pointer) &ia;
    byte_pointer inb = (byte_pointer) &ina;
    byte_pointer ub = (byte_pointer) &ua;
    byte_pointer lb = (byte_pointer) &la;
    byte_pointer fb = (byte_pointer) &fa;

    show_bytes(ib,sizeof(int));
    show_bytes(inb,sizeof(int));
    show_bytes(ub,sizeof(unsigned));
    show_bytes(lb,sizeof(long));
    show_bytes(fb,sizeof(float));
    return 0;
}
