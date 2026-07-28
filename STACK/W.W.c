// Check whether the given string is of the form w.w using a queue.
//abc.abc,a.a,abc.abd,ab.abc,abc.ab,abc.,.abc,.,<Enter>,abc,abc..abc,..,123.123,abc.abcx,abcx.abc

#include<stdio.h>
#define MAX 10
typedef enum{ FALSE,TRUE}BOOL;
typedef struct{ int val[MAX]; int rear,front; }QUEUE;
void createQueue(QUEUE *q);
BOOL isEmpty(QUEUE q);
BOOL isFull(QUEUE q);
BOOL Insert(QUEUE *q,char data);
BOOL Delete(QUEUE *q,char *data);
int size(QUEUE q);
void display(QUEUE q);

BOOL checkWW(char s[]){
    QUEUE q1;
    createQueue(&q1);
    int i=0; char x;
    while(s[i]!='\0' && s[i]!='.'){
        Insert(&q1,s[i]); i++; 
    }
    if(s[i]=='.') i++;// skip the period '.'
    while(s[i]!='\0' && s[i]!='\n'){
        if(Delete(&q1,&x)){
            if(x!=s[i]) return FALSE;
        }
        else return FALSE;
        i++;
    }
    if(!isEmpty(q1)) return FALSE;
    return TRUE;
}
//MAIN
int main(){

    char str1[100];
    printf("Enter String (w.w) : ");
    fgets(str1,sizeof(str1),stdin);

    BOOL b=checkWW(str1);
    
    if(b)
        printf("YES it is in w.w form\n");
    else
        printf("NO it is not in w.w form\n");
    return 0;
}


//QUEUE IMPLEMENTAATIONS IN C
void createQueue(QUEUE *q){
    q->rear=q->front=0;
}

BOOL isEmpty(QUEUE q){ return q.front==q.rear;}
BOOL isFull(QUEUE q){ return (q.rear+1)%MAX==q.front;  }

BOOL Insert(QUEUE *q,char data){
    if(isFull(*q)) return FALSE;
    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=data;
    return TRUE;
}

BOOL Delete(QUEUE *q,char *data){
    if(isEmpty(*q)) return FALSE;
    q->front=(q->front+1)%MAX;
    *data=q->val[q->front];
    return TRUE;
}

int size(QUEUE q){
   return (q.rear-q.front+MAX)%MAX;
}

void display(QUEUE q){
    char v;
    printf("the Queue :\n");
    for(int i=0;i<=size(q);i++)
    {
        Delete(&q,&v);
        printf("%d ",v);
    }
    printf("\n");
}
