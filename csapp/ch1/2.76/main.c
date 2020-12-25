#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include<assert.h>

/* Determine whether arguments can be multiplied without overflow
 * Practice Problem 2.35 */
int mult_ok(size_t x, size_t y){
    size_t p =x*y;
    /* Either x is zero, or dividing p by x gives y*/
    return !x || p/x == y;
}

void *another_calloc(size_t nmemb,size_t size){
    if(nmemb==0||size==0){
        return NULL;
    }
    if(mult_ok(nmemb,size)){
        size_t buf_size = nmemb*size;
        void* ptr = malloc(buf_size);
        if(ptr!=NULL){
            memset(ptr,0,buf_size);
        }
        return ptr;
    }
    return NULL;
}

int main(void){
    int n = 5;
    char *a,*b;
    int i;

    a=(char*)calloc(n,sizeof(char));
    for(i=0;i<n;i++){
        a[i]='a';
    }
    printf("%s\n",a);
    free(a);

    b=(char*)another_calloc(n,sizeof(char));
    for(i=0;i<n;i++){
        b[i]='b';
    }
    printf("%s\n",b);
    free(b);

    void *p;
    p=another_calloc(1,1);
    assert(p!=NULL);
    free(p);

    p=another_calloc(0,2);
    assert(p == NULL);
    free(p);

    p=another_calloc(SIZE_MAX,3);
    assert(p == NULL);
    free(p);

    printf("int bytes count: %lu\n",sizeof(int));
    printf("unsigned bytes count: %lu\n",sizeof(unsigned));
    printf("float bytes count: %lu\n",sizeof(float));
    printf("double bytes count: %lu\n",sizeof(double));
    printf("pointer bytes count: %lu\n",sizeof(void*));
    printf("size_t bytes count: %lu\n",sizeof(size_t));
    return 0;
}
