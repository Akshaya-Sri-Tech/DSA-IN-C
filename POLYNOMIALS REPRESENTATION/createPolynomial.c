//C program to create a polynomial and attach terms using structures, combining like terms with the same exponent.

#include<stdio.h>
typedef struct{
    int coeff,exp;
}TERM;
typedef struct{
    int n;
    TERM p[100];
}POLY;

POLY createPoly(){
    POLY pol;
    pol.n=0;
    return pol;
}
POLY attachPoly(POLY pol,TERM t){
    POLY p1=pol;
    p1.p[p1.n]=t;
    p1.n=p1.n+1;

    for(int i=0;i<p1.n;i++){
        for(int j=i+1;j<p1.n;j++)
            if(p1.p[i].exp==p1.p[j].exp)
            {
                 p1.p[i].coeff+=p1.p[j].coeff;
                 p1.p[j].exp=0;
            }
    }

    return p1;
}
void printPoly(POLY pol){
    for(int i=0;i<pol.n;i++)
    {
        if(pol.p[i].exp!=0)
         printf("%dx^%d ",pol.p[i].coeff,pol.p[i].exp);
    }

}

int main()
{
    TERM t1={2,12},t2={3,12},t3={4,17};
    POLY p1;
    p1=createPoly();
    p1=attachPoly(p1,t1);
    p1=attachPoly(p1,t2);
    p1=attachPoly(p1,t3);
    printPoly(p1);
}
