#include <stdio.h>
#include <stdlib.h>
#define N 3

int used[N]={0};
int source[N]={1,2,3};

void print_int_array(int a[N]){
    int i;
    for (i=0;i<N;i++){
        if (i!=N-1){
            printf("%d\t",a[i]);
        }else{
            printf("%d\n",a[i]);
        }
    }
    return;
}

void dfs(int path[N],int used[N],int depth){
    int i;
    if (depth==N){
        print_int_array(path);
        return;
    }
    for (i=0;i<N;i++){
        if (used[i]==0){
            depth++;
            path[depth-1]=source[i];
            used[i]=1;
            dfs(path,used,depth);
            path[depth-1]=0;
            used[i]=0;
            depth--;
        }else{
            continue;
        }
    }
    return;
}

int main(void){
    int path[N]={0};
    int depth = 0;
    dfs(path,used,depth);
    return 0;
}
