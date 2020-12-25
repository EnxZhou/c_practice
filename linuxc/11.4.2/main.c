#include<stdio.h>

#define LEN 8
int a[LEN]={5,2,4,7,1,3,2,6};

int partition(int start,int end){
    int left,right,pivot;
    left=start;
    right=end;
    pivot=a[start];
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
        // 这里判断left<right是必须的，有可能left等于right。
        if(left<right){
            a[right]=a[left];
            right--;
        }
    }
    a[left]=pivot;
    return left;
}

void quicksort(int start,int end){
    int mid;
    if (end>start){
        mid=partition(start,end);
        quicksort(start,mid-1);
        // 最初忘记mid+1，mid有可能为quicksort的参数start，这样会造成无法停止，
        // 不断运行quicksort(0,4)
        quicksort(mid+1,end);
    }
}

int main(void){
    quicksort(0,7);
    int i;
    for (i=0;i<LEN-1;i++){
        printf("%d\t",a[i]);
    }
    printf("%d\n",a[LEN-1]);
    return 0;
}
