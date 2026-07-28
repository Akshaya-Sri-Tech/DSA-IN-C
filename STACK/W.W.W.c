//Check whether a given string is of the form w.w.w, where all three substrings are identical
//abc.abc.abc,a.a.a,abc.abc.abd,abc.ab.abc,ab.abc.abc,abc..abc,.abc.abc,abc.abc.,..,.,abc,abc.,.abc,abc.abc.abcx,abcx.abc.abc,abc.abcx.abc,abc..,123.123.123,<Enter>

#include<stdio.h>
#define MAX 10
typedef enum{ FALSE,TRUE}BOOL;
typedef struct{ char val[MAX]; int rear,front; }QUEUE;
void createQueue(QUEUE *q);
BOOL isEmpty(QUEUE q);
BOOL isFull(QUEUE q);
BOOL Insert(QUEUE *q,char data);
BOOL Delete(QUEUE *q,char *data);
int size(QUEUE q);
void display(QUEUE q);

BOOL checkWWW(char s[]){
    QUEUE q1;
    createQueue(&q1);
    int i=0; char x;
    while(s[i]!='\0' && s[i]!='.'){
        Insert(&q1,s[i]); i++; 
    }
    int check=0;//this is used to make sure there is a second word and . is not immediately followed by another .
    if(s[i]=='.') i++;// skip the 1st period '.'
    while(s[i]!='\0' && s[i]!='.'){
        if(Delete(&q1,&x)){
            Insert(&q1,s[i]);
            if(x!=s[i]) return FALSE;
        }
        else return FALSE;
        i++;
        check=1;
    }
    if(check!=1) return FALSE;
    if(s[i]=='.') i++;// skip the 2nd period '.'
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
    printf("Enter String (w.w.w) : ");
    fgets(str1,sizeof(str1),stdin);

    BOOL b=checkWWW(str1);
    
    if(b)
        printf("YES it is in w.w.w form\n");
    else
        printf("NO it is not in w.w.w form\n");
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
