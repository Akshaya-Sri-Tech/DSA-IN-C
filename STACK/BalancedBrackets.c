//to check whether a given sequence of '(' and ')' brackets is balanced or not.

#include<stdio.h>
#include<string.h>
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

BOOL isBalanced(char str[]){
    STACK s1;
    s1=createStack();
    int i=0; char x;
    while(str[i]!='\0'){
    if(str[i]=='(') push(&s1,str[i]);
    if(str[i]==')'){
        if(isEmpty(s1)) return FALSE;
        pop(&s1,&x);
    }
    i++;
    }
    if(!isEmpty(s1)) return FALSE;
    return TRUE;
}

int main()
{
    char str[100];
    printf("Enter the bracket sequence : ");
    fgets(str,sizeof(str),stdin); // fgets used instead of scanf to handle when the edge case "enter" is given 

    BOOL b=isBalanced(str);
    if(b){ printf("YES it is balanced\n");}
    else
        printf("NO It is not balnced\n");

}

// STACK IMPLEMENTATIONS IN C
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
