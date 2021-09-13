#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>
#include<limits.h>
#include "bitshow.h"

int random_int() {
    return rand();
}

int init_seek() {
    srand((int)time(0));
}

int A(int x){
    double dx = (double) x;
    return (float) x == (float) dx;
}

int B(int x, int y){
    double dx = (double) x;
    double dy = (double) y;
    return (dx-dy) == (double)(x-y);
}

int C(int x,int y,int z){
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;
    return (dx+dy)+dz==dx+(dy+dz);
}

int D(int x,int y,int z){
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;

    printf("dx: ");
    show_double(dx);
    printf("dy: ");
    show_double(dy);
    printf("dz: ");
    show_double(dz);
    printf("dx*dy: ");
    show_double(dx*dy);
    printf("dy*dz: ");
    show_double(dy*dz);
    printf("(dx*dy)*dz: ");
    show_double((dx*dy)*dz);
    printf("dx*(dy*dz): ");
    show_double(dx*(dy*dz));
    return (dx*dy)*dz==dx*(dy*dz);
}

int E(int x,int z){
    double dx = (double) x;
    double dz = (double) z;
    return dx/dx == dz/dz;
}

int main(void) {
    /* Create some arbitrary values */
    init_seek();
    int x = random_int();
    int y = random_int();
    int z = random_int();
    printf("x = %.8x\n",x);
    printf("y = %.8x\n",y);
    printf("z = %.8x\n",z);

    assert(A(x));
    assert(!B(INT_MIN,1));
    assert(C(x,y,z));
    assert(!D(0x63b493ac,0x1370f6d9,0x39b85c60));
    assert(!E(1,0));
}
