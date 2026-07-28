//Check whether a given string is of the form w.w.wᴿ
//abc.abc.cba,a.a.a,ab.ab.ba,abc.abc.abc,abc.abc.cab,abc.ab.cba,ab.abc.cba,abc..cba,.abc.cba,abc.abc.,..,.,abc,abc.,.abc,abc.abc.cbaa,abcx.abc.cbax,123.123.321,<Enter>,aaa.aaa.aaa,abc.cba.cba,a..a,a.a.,.a.a,...,a.a.a.,a.a.a.a

#include<stdio.h>
#define MAX 10
typedef enum{ FALSE,TRUE}BOOL;

typedef struct{ char val[MAX]; int top; }STACK;
typedef struct{ char val[MAX]; int rear,front; }QUEUE;
//STACK
STACK createStack();
BOOL isEmptyS(STACK s);
BOOL isFullS(STACK s);
BOOL pushS(STACK *s,char v);
BOOL popS(STACK *s,char *v);
void displayS(STACK s);

//QUEUE
void createQueue(QUEUE *q);
BOOL isEmptyQ(QUEUE q);
BOOL isFullQ(QUEUE q);
BOOL InsertQ(QUEUE *q,char data);
BOOL DeleteQ(QUEUE *q,char *data);
int size(QUEUE q);
void displayQ(QUEUE q);

BOOL checkWWWrev(char s[]){
    QUEUE q1;   createQueue(&q1);
    STACK s1;   s1=createStack();
    
    int i=0; char x;
    while(s[i]!='\0' && s[i]!='.'){
        InsertQ(&q1,s[i]); i++; 
    }
    int check=0;//this is used to make sure there is a second word and . is not immediately followed by another .
    if(s[i]=='.') i++;// skip the 1st period '.'
    while(s[i]!='\0' && s[i]!='.'){
        if(DeleteQ(&q1,&x)){
            pushS(&s1,s[i]);
            if(x!=s[i]) return FALSE;
        }
        else return FALSE;
        i++;
        check=1;
    }
    if(check!=1) return FALSE;
    if(s[i]=='.') i++;// skip the 2nd period '.'
    while(s[i]!='\0' && s[i]!='\n'){
        if(popS(&s1,&x)){
            if(x!=s[i]) return FALSE;
        }
        else return FALSE;
        i++;
    }
    if(!isEmptyQ(q1) || !isEmptyS(s1)) return FALSE;
    return TRUE;
}
//MAIN
int main(){

    char str1[100];
    printf("Enter String (w.w.w-reverse) : ");
    fgets(str1,sizeof(str1),stdin);

    BOOL b=checkWWWrev(str1);
    
    if(b)
        printf("YES it is in w.w.w-reverse form\n");
    else
        printf("NO it is not in w.w.w-reverse form\n");
    return 0;
}

// STACK IMPLEMENTATIONS IN C

STACK createStack(){
    STACK s;
    s.top=0;
    return s;
}

BOOL isEmptyS(STACK s){
    if(s.top==0) return TRUE;
    return FALSE;
}

BOOL isFullS(STACK s){
    if(s.top==MAX-1) return TRUE;
    return FALSE;
}

BOOL pushS(STACK *s,char v){
    if(isFullS(*s)) return FALSE;
    s->top+=1;
    s->val[s->top]=v;
    return TRUE;
}

BOOL popS(STACK *s,char *v){
    if(isEmptyS(*s)) return FALSE;
    *v=s->val[s->top];
    (s->top)-=1;
    return TRUE;
}

void displayS(STACK s){
while(!isEmptyS(s)){
        char x;
        popS(&s,&x);
        printf("%c ",x);
    }
}

//QUEUE IMPLEMENTAATIONS IN C
void createQueue(QUEUE *q){
    q->rear=q->front=0;
}

BOOL isEmptyQ(QUEUE q){ return q.front==q.rear;}
BOOL isFullQ(QUEUE q){ return (q.rear+1)%MAX==q.front;  }

BOOL InsertQ(QUEUE *q,char data){
    if(isFullQ(*q)) return FALSE;
    q->rear=(q->rear+1)%MAX;
    q->val[q->rear]=data;
    return TRUE;
}

BOOL DeleteQ(QUEUE *q,char *data){
    if(isEmptyQ(*q)) return FALSE;
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
        DeleteQ(&q,&v);
        printf("%d ",v);
    }
    printf("\n");
}