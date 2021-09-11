#include<stdio.h>
#include<assert.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

int random_int(){
    return rand();
}

int init_seek(){
    srand((int)time(0));
}

int A(int x, int y) {
    return (x < y) == (-x > -y);
}

int B(int x, int y) {
    return ((x+y)<<4) + y-x == 17*y+15*x;
}

int C(int x, int y) {
    return ~x+~y+1 == ~(x+y);
}

int D(int x, int y) {
    /* Convert to unsigned */
    unsigned ux = (unsigned) x;
    unsigned uy = (unsigned) y;
    return (ux-uy) == -(unsigned)(y-x);
}

int E(int x, int y) {
    return ((x>>2) <<2)<=x;
}

int main(void){
    /* Create some arbitrary values */
    init_seek();
    int x = random_int();
    int y = random_int();
    printf("x = %.8x\n",x);
    printf("y = %.8x\n",y);
    assert(A(x,y));
    assert(!A(INT_MIN,0));
    assert(B(x,y));
    assert(C(x,y));
    assert(D(x,y));
    assert(E(x,y));

    return 0;
}

