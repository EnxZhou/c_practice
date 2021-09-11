#include<stdio.h>
#include<math.h>
#include<assert.h>

float u2f(unsigned x){
    return *(float*) &x;
}

float fpwr2(int x){
    /* Result exponent and fraction */
    unsigned exp,frac;
    unsigned u;

    if (x<-149){
        /* Too small. Return 0.0 */
        exp = 0;
        frac = 0;
    } else if (x < -126) {
        /* Denormalized result */
        exp = 0;
        frac = 1<<(x+149);
    } else if (x < 128) {
        /* Normalized result. */
        exp = x+127;
        frac = 0;
    } else {
        /* Too big. Return +oo */
        exp = (1<<8)-1;
        frac = 0;
    }

    /* Pack exp and frac into 32 bits */
    u = exp << 23 | frac;
    /* Return as float */
    return u2f(u);
}

int main(void) {
    assert(fpwr2(-150)==powf(2,-150));
    assert(fpwr2(-130)==powf(2,-130));
    assert(fpwr2(1)==powf(2,1));
    assert(fpwr2(128)==powf(2,128));
}
