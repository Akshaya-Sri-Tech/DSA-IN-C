#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
void countingSort(int A[],int n,int B[]){
    int freq[MAX+1]={0};
    for(int i=0;i<n;i++) freq[A[i]]++;
    for(int i=1;i<=MAX;i++) freq[i]+=freq[i-1];
    for(int i=n-1;i>=0;i--) B[--freq[A[i]]]=A[i];
}

int main(){
    int N=10;
    int A[N];
    for(int i=0;i<N;i++){
        A[i]=rand()%100;
        printf("%5d",A[i]);
    }
    printf("\n");
    int B[N];
    countingSort(A,N,B);
    for(int i=0;i<N;i++){
        printf("%5d",B[i]);
    }
}