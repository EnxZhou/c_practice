#include<stdio.h>
#include<limits.h>

int second_of(int b[],int size){
    int first,second;
    int i;
    first=INT_MAX;
    second=INT_MAX;
    for(i=0;i<size;i++){
        if (b[i]<first){
            second=first;
            first=b[i];
        }else if (b[i]<second){
            second=b[i];
        }
    }
    return second;
}

int main(void){
    int a[8] = {4,5,7,4,3,8,1,6};
    printf("the second num is: %d\n",second_of(a,8));
    return 0;
}
