//power set

#include<stdio.h>
void powerSet(int arr[],int size,int n,int subset,int s_size){
    if(n==0) {  printf("{}"); return; }
    powerSet(arr,size,n-1,subset,n-1);

    for(int i=n;i<size;i++){
        printf(" {");
        for(int k=i;k<size;k++){
            printf("%d ",arr[k]);
        }
        printf("} ");
    }
}

int main(){
    int n;
    printf("Enter n:");
    scanf("%d",&n);

    int arr[n],subset[n];
    printf("Enter the set elements :\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        subset[i]=arr[i];
    }
    
    printf("POWER SET :\n");
    powerSet(arr,n,n,subset,n);

    return 0;
}