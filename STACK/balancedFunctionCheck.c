//Check whether a given function call–return sequence follows the LIFO

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

BOOL isBalanced(char s[]){
    STACK s1;
    s1=createStack();
    int i=0;
    while(s[i]!='\0'){
        if(s[i]>='A' && s[i]<='Z')
            push(&s1,s[i]);
        if(s[i]>='a' && s[i]<='z'){
            char x;
            pop(&s1,&x);
            if(x!=s[i]-32) return FALSE;
        }
        i++;
    }
    if(!isEmpty(s1)) return FALSE; 
    return TRUE;
}

int main(){
    char str[100];
    printf("Enter the function_call-return sequence : ");
    fgets(str,sizeof(str),stdin); // fgets used instead of scanf to handle when the edge case "enter" is given 

    BOOL b=isBalanced(str);
    if(b){ printf("YES it is a balanced Function_call-Return\n");}
    else
        printf("NO It is not a balanced Function_call-Return\n");
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
