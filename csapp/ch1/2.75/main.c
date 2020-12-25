#include<stdio.h>
#include<assert.h>
#include<stdint.h>

int signed_high_prod(int x, int y){
    int64_t mul = (int64_t) x * y;
    return mul>>32;
}

unsigned real_unsigned_high_prod(unsigned x, unsigned y){
    uint64_t mul = (uint64_t) x * y;
    return mul>>32;
}

/* ux,uy represent unsigned type number;
 * x,y represent int type number;
 * xw_1 represent highest bit of int type number x;
 * yw_1 represent highest bit of int type number y;
 * shp represent signed_high_prod(x,y)*
 * ushp represent unsigned_high_prod(ux,uy)*/

/* as formula 2.18, ux=x+xw_1*2^w, uy=y+yw_1*2^w;
 * ux*uy=(x+xw_1*2^w)*(y+yw_1*2^w)
 *      =x*y+y*xw_1*2^w+x*yw_1*2^w+xw_1*yw_1*2^(2w)
 * as the inference of formula 2.18: (ux*uy)mod(2^w)=(x*y)mod(2^w)
 * that mean the lowest w bit of (ux*uy) and (x*y) are same,
 * the lowest w bit of y*xw_1*2^w+x*yw_1*2^w+xw_1*yw_1*2^(2w) are all zero;
 * thus extracting highest w bit of both sides of formula in line 23 we get follow:
 * ushp=shp+y*xw_1+x*yw_1
 * this is the result.*/

unsigned unsigned_high_prod(unsigned x, unsigned y){
/*
 * x,y is unsigned type number, the right shifting is logical shift,
 * so in follow function, xw_1 and yw_1 number is 0x00000000 or 0x00000001;
 */
    /* solution one
    int xw_1 = x>>31;
    int yw_1 = y>>31;
    int xw_mul_y=0;
    int yw_mul_x=0;
    xw_1&&(xw_mul_y=y);
    yw_1&&(yw_mul_x=x);
    unsigned ushp = signed_high_prod(x,y)+xw_mul_y+yw_mul_x;
    */

/*
 * convert unsigned type to int type,
 * the right shifting is arithmetical shift,
 * so in follow function, xw_1 and yw_1 number is 0x00000000 or 0xFFFFFFFF;
 * so xw_1*y equal to xw_1_mask&y.
 */
    int xw_1_mask = ((int) x)>>31;
    int yw_1_mask = ((int) y)>>31;
    unsigned ushp = signed_high_prod(x,y) + (xw_1_mask&y) + (yw_1_mask&x);
    printf("%.8x\n",ushp);
    return ushp;
}

int main(void){
    unsigned x = 0x12345678;
    unsigned y = 0xffffffff;
    assert(real_unsigned_high_prod(x,y) == unsigned_high_prod(x,y));
    return 0;
}
