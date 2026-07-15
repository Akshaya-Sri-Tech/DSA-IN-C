//Addition of two polynomials using array representation in C.

#include<stdio.h>
void getPoly(int p[])
{
    printf("Enter the coefficient and exponnents :\n");
    int n=2*p[0]+1;
    for(int i=1;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
}
void display(int p[])
{
    int size=2*p[0]+1;
    for(int i=1;i<size;i+=2)
    {
        printf("%dx^%d ",p[i],p[i+1]);
    }
    printf("\n");
}

int main()
{
    int n1,m1;
    printf("Enter the number of terms in 1st and 2nd polynomial :\n");
    scanf("%d%d",&n1,&m1);

    int p1[2*n1+1],p2[2*m1+1];
    p1[0]=n1,p2[0]=m1;
    getPoly(p1);
    getPoly(p2);

    printf("Polynomial 1:\n");
    display(p1);
    printf("Polynomial 2:\n");
    display(p2);

    int sum[100];
    int count=0;
    int i=1,j=1,k=1;
    while(i<=2*p1[0] && j<=2*p2[0])
    {
        if(p1[i+1]>p2[j+1]){
            sum[k]=p1[i];
            sum[k+1]=p1[i+1];
            i+=2;
            k+=2;
            count++;
        }
        else if(p1[i+1]<p2[j+1]){
            sum[k]=p2[j];
            sum[k+1]=p2[j+1];
            j+=2;
            k+=2;
            count++;
        }
        else{
            if((p1[i]+p2[j])!=0){
                sum[k]=p1[i]+p2[j];
                sum[k+1]=p1[i+1];
                k+=2;
                count++;
            }
            i+=2;
            j+=2;
        }
    }
    while(i<=2*p1[0])
    {
        sum[k]=p1[i];
        sum[k+1]=p1[i+1];
        i+=2; k+=2; count++;
    }
    while(j<=2*p2[0])
    {
        sum[k]=p2[j];
        sum[k+1]=p2[j+1];
        j+=2; k+=2;count++;
    }

    sum[0]=count;

    printf("The sum is :\n");
    display(sum);
}
