#include<stdio.h>
#define MAX 1000000

// HEap sort
int a[MAX];
int n;
void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}

void swap(int i,int j){
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}
void heapify(int i,int N){
    int L=2*i;
    int R=2*i+1;
    int max=i;
    if(L<=N&&a[L]>a[i]) max=L;
    if(R<=N&&a[R]>a[max]) max=R;
    if(max!=i){
        swap(i,max);
        heapify(max,N);
    }
}
void buildHeap(){
    for(int i=n/2;i>=1;i--)
        heapify(i,n);
}

void heapSort(){
    buildHeap();
    for(int i=n;i>1;i--){
        swap(1,i);
        heapify(1,i-1);
    }
}
void printResult(){
    for(int i=1;i<=n;i++)
        printf("%d  ",a[i]);
    printf("\n");
}

int main(){
    input();
    heapSort();
    printResult();

}