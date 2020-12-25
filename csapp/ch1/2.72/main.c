#include<stdio.h>
#include<string.h>

void copy_int(int val, void *buf, int maxbytes){
    printf("maxbytes: %.8x\n",maxbytes);
    printf("%d\n",(maxbytes-sizeof(val))>=0);
    printf("%d\n",(maxbytes>=(int)sizeof(val)));
    if (maxbytes>=(int)sizeof(val))
        memcpy(buf,(void *) &val,sizeof(val));
}

int main(void){
    int a = 1;
    int c = 0;
    int *b = &c;
    copy_int(a,b,4);
    printf("b: %d\n",*b);
    return 0;
}
