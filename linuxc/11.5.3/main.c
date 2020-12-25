#include<stdio.h>
#define LEN 8

int a[LEN]={4,3,6,7,5,1,2,8};

int partition(int left,int right){
    int pivot;
    pivot=a[left];
    while(left<right){
        while(left<right && a[right]>pivot){
            right--;
        }
        if(left<right){
            a[left]=a[right];
            left++;
        }
        while(left<right && a[left]<pivot){
            left++;
        }
        if(left<right){
            a[right]=a[left];
            right--;
        }
    }
    a[left]=pivot;
    return left;
}
int order_statistic(int start,int end,int k){
    int abs_p,i;
    abs_p=partition(start,end);
    i=abs_p-start+1;
    if(k == i)
        return a[abs_p];
    else if (k>i)
        return order_statistic(abs_p+1,end,k-i);
    else
        return order_statistic(start,abs_p-1,k);
}

int main(void){
    int res;
    res=order_statistic(0,LEN-1,5);
    printf("%d\n",res);
    return 0;
}
