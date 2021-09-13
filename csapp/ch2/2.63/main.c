#include<stdio.h>

int w = 8*sizeof(int);

unsigned srl(unsigned x,int k){
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;
    unsigned a = (1<<(w-k))-1;
    return xsra & a;

}

int sra(int x,int k){
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;
    unsigned sign_mask = 1<<(w-k-1);
    unsigned sign = xsrl & sign_mask;
    return xsrl | (~(sign-1));
}

int main(void){
    unsigned x;
    int sk;
    sk=4;
    x=0xffff0000;
    printf("%.8x shift logically amount %d result is: %.8x\n",x,sk,srl(x,sk));
    printf("%.8x shift arithmetically amount %d result is: %.8x\n",x,sk,sra((unsigned)x,sk));
    sk=1;
    x=0xffff000f;
    printf("%.8x shift logically amount %d result is: %.8x\n",x,sk,srl(x,sk));
    printf("%.8x shift arithmetically amount %d result is: %.8x\n",x,sk,sra((unsigned)x,sk));
    sk=31;
    x=0x000f000f;
    printf("%.8x shift logically amount %d result is: %.8x\n",x,sk,srl(x,sk));
    printf("%.8x shift arithmetically amount %d result is: %.8x\n",x,sk,sra((unsigned)x,sk));
    return 0;
}
