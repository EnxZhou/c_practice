#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer x,size_t l){
    int i;
    for(i=0;i<l;i++){
        printf("%.2x",x[i]);
    }
    printf("\n");
}

byte_pointer char_combin(int *x,int *y){
    byte_pointer least = (byte_pointer) x;
    byte_pointer remain = (byte_pointer) y;
    byte_pointer res = (byte_pointer) x;
    printf("least in char_combin: ");
    show_bytes(least,sizeof(int));
    printf("remain in char_combin: ");
    show_bytes(remain,sizeof(int));
    res[0]=least[0];
    int i;
    for(i=1;i<sizeof(int);i++){
        res[i]=remain[i];
    }
    return res;
}

int int_combin(int x,int y){
    int least_x = x & 0x00000FF;
    int remain_y = y & 0xFFFFFF00;
    byte_pointer least = (byte_pointer) &least_x;
    byte_pointer remain = (byte_pointer) &remain_y;
    printf("least in int_combin: ");
    show_bytes(least,sizeof(int));
    printf("remain in int_combin: ");
    show_bytes(remain,sizeof(int));
    return least_x+remain_y;
}

int main(void){
    int x = 0x89ABCDEF;
    int y = 0x76543210;
    byte_pointer res = char_combin(&x,&y);
    printf("result of char_combin: ");
    show_bytes(res,sizeof(int));
    int ires = int_combin(x,y);
    printf("result of int_combin: %x\n",ires);
}
