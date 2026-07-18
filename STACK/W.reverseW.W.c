//Check whether a given string follows the pattern w · reverse(w) · w
//abc.cba.abc, a.a.a, abc.cba.cba, abc.abc.abc, abc.cba, abc.cba., abc..abc, .cba.abc, abc.cba., abc, ., abc., empty input

#include<stdio.h>
#define MAX_SIZE 10

typedef struct{
    int val[MAX_SIZE];
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
    STACK s1,s2;
    s1=createStack();
    s2=createStack();
    char str[100];
    printf("Enter the sequence : ");
    fgets(str, sizeof(str), stdin);

    int check=1;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='.') break;
        push(&s1,str[i]);
        i++;
    }
    i++;

    while(str[i]!='\0'){
        if(str[i]=='.') break;
        if(str[i]=='\n'){ // for edge case : abc.   
        int j=i-1;
        if(str[j]=='.') check=0; 
        break;
        }
        char x;
        if(!pop(&s1,&x)){
            check=0; break;
        };
        if(x!=str[i]) check=0;
        push(&s2,str[i]);
        i++;
    }
    i++;

    if(isEmpty(s1)){
        while(str[i]!='\0'){
            if(str[i]=='\n'){ // for edge case : abc.   
            int j=i-1;
            if(str[j]=='.') check=0; 
            break;
            }
            char x;
            if(!pop(&s2,&x)){
                check=0; break;
            };
            if(x!=str[i]) check=0;
            i++;
        }
    }
    else{ check=0;}
    if(!isEmpty(s2)) check=0;
    if(check)
        printf("YES, It is in (w.w-reverse.w) form\n");
    else
        printf("NO, It is not in (w.w-reverse.w) form\n");
    return 0;

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
