#include<stdio.h>
#include<assert.h>
#include "p2.h"

// typedef enum {NEG,ZERO,POS,OTHER} range_t;
int find_range_f(float f) {
    int result;
    if (f<0)
        result = NEG;
    else if (f==0)
        result = ZERO;
    else if (f>0)
        result = POS;
    else
        result = OTHER;
    return result;
}

int main(){
    assert(find_range_f(1)==find_range(1));
    assert(find_range_f(-1)==find_range(-1));
    assert(find_range_f(0)==find_range(0));
    assert(find_range_f(1/0.0)==find_range(1/0.0));
    return 0;
}