#include<stdio.h>
unsigned any_eq_1(int x){
    return !(~x);
}

unsigned any_eq_0(int x){
    return !x;
}

unsigned least_eq_1(int x){
    return !(~x&0x000000ff);
}

unsigned most_eq_0(int x){
    return !(x&0xff000000);
}

int main(void){
    int x;
    x=0xffffffff;
    printf("----%.8x----\n",x);
    printf("any bit equals 1:%d\n",any_eq_1(x));
    printf("any bit equals 0:%d\n",any_eq_0(x));
    printf("least bit equals 1:%d\n",least_eq_1(x));
    printf("most bit equals 0:%d\n",most_eq_0(x));
    x=0x0fffafff;
    printf("----%.8x----\n",x);
    printf("any bit equals 1:%d\n",any_eq_1(x));
    printf("any bit equals 0:%d\n",any_eq_0(x));
    printf("least bit equals 1:%d\n",least_eq_1(x));
    printf("most bit equals 0:%d\n",most_eq_0(x));
    x=0xff1ffff0;
    printf("----%.8x----\n",x);
    printf("any bit equals 1:%d\n",any_eq_1(x));
    printf("any bit equals 0:%d\n",any_eq_0(x));
    printf("least bit equals 1:%d\n",least_eq_1(x));
    printf("most bit equals 0:%d\n",most_eq_0(x));
    x=0x00000000;
    printf("----%.8x----\n",x);
    printf("any bit equals 1:%d\n",any_eq_1(x));
    printf("any bit equals 0:%d\n",any_eq_0(x));
    printf("least bit equals 1:%d\n",least_eq_1(x));
    printf("most bit equals 0:%d\n",most_eq_0(x));
    x=0x002123ff;
    printf("----%.8x----\n",x);
    printf("any bit equals 1:%d\n",any_eq_1(x));
    printf("any bit equals 0:%d\n",any_eq_0(x));
    printf("least bit equals 1:%d\n",least_eq_1(x));
    printf("most bit equals 0:%d\n",most_eq_0(x));

    return 0;
}
