#include<stdio.h>
#include<string.h>
#include<limits.h>
#include "bitshow.h"

void show_bytes(byte_pointer,size_t);
void show_short(short x);
void show_int(int x);
void show_long(long x);
void show_double(double x);
void show_float(float x);
void show_pointer(void *x);
void show_unsigned(unsigned x);
int uadd_ok(unsigned x,unsigned y);
int tadd_ok(int x, int y);
int tsub_ok(int x,int y);
int is_little_endian();

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

void show_float(float x){
    show_bytes((byte_pointer) &x,sizeof(double));
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
int uadd_ok(unsigned x,unsigned y){
    unsigned sum = x+y;
    return sum>=x;
}

int tadd_ok(int x, int y){
    int sum=x+y;
    int pos_over = x>0&&y>0&&sum<=0;
    int neg_over = x<0&&y<0&&sum>=0;
    return !pos_over && !neg_over;
}

int tsub_ok(int x,int y){
    if(x<0&&y==INT_MIN){
        return 1;
    }
    return tadd_ok(x,-y);
}
int is_little_endian(){
    unsigned a = 1;
    unsigned char *b = (unsigned char *) &a;
    return b[0];
}
