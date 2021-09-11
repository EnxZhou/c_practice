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

void show_short(short x){
    show_bytes((byte_pointer) &x,sizeof(short));
}

void show_int(int x) {
    show_bytes((byte_pointer) &x,sizeof(int));
}

void show_long(long x){
    show_bytes((byte_pointer) &x,sizeof(long));
}

void show_double(double x){
    show_bytes((byte_pointer) &x,sizeof(double));
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x,sizeof(void *));
}

void show_unsigned(unsigned x){
    show_bytes((byte_pointer) &x,sizeof(unsigned));
}

int main(){
    short sa = 1;
    long la = 1;
    double da = 1;
    
    show_short(sa);
    show_long(la);
    show_double(da);
    return 0;
}
