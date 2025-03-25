#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int *b= (int*)malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }
    for(int i=0; i<n; i++){
        b[i] = a[i] + b[i];
    }
    for(int i=0; i<n; i++){
        printf("%d ", b[i]);
    }
    free(a);
    free(b);
    return 0;

}