// fully paranthesised infix -> postfix

#include<stdio.h>
#define MAX_SIZE 10

typedef struct{
    char val[MAX_SIZE];
    int top;
}STACK;
typedef enum{ FALSE,TRUE }BOOL;
STACK createStack();
BOOL isEmpty(STACK s);
BOOL isFull(STACK s);
BOOL push(STACK *s,char v);
BOOL pop(STACK *s,char *v);
void display(STACK s);


int main(){

    STACK s1;
    s1=createStack();
    char str[100];
    printf("Enter Expression :");
    fgets(str,sizeof(str),stdin);

    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='('){ i++; continue;}
        else if(str[i]>='a' && str[i]<='z') {printf("%c",str[i]);}
        else if(str[i]==')')
        {
            char x;
            pop(&s1,&x);
            if(x==':') printf("?");
            printf("%c",x);
            
        }
        else
            push(&s1,str[i]);
        i++;
    }
    return 0;
}

//STACK IMPLEMENTATION IN C
STACK createStack(){
    STACK s;
    s.top=0;
    return s;
}

BOOL isEmpty(STACK s){
    if(s.top==0) return TRUE;
    return FALSE;
}

BOOL isFull(STACK s){
    if(s.top==MAX_SIZE-1) return TRUE;
    return FALSE;
}

BOOL push(STACK *s,char v){
    if(isFull(*s)) return FALSE;
    s->top+=1;
    s->val[s->top]=v;
    return TRUE;
}

BOOL pop(STACK *s,char *v){
    if(isEmpty(*s)) return FALSE;
    *v=s->val[s->top];
    (s->top)-=1;
    return TRUE;
}

void display(STACK s){
while(!isEmpty(s)){
        char x;
        pop(&s,&x);
        printf("%c ",x);
    }
}
