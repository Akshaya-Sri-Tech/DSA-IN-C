//check whether the given string is of the form , (w.w-reverse) eg:abc.cba
//Edge Cases : abc. , abc , abc.cb , abc.cbad , abc.ca , .  

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

//main()
int main(){
    STACK s1;
    s1=createStack();
    char str[100];
    printf("Enter the sequence : ");
    fgets(str, sizeof(str), stdin);

    int i=0;
    int check=1;
    while(str[i]!='\0'){
        if(str[i]=='.') break;
        push(&s1,str[i]);
        i++;
    }
    i++;

    while(str[i]!='\0'){
        if(str[i]=='\n'){    
        int j=i-1;
        if(str[j]=='.') check=0; 
        break;
        }
        char x;
        if(!pop(&s1,&x)){
            check=0; break;
        };
        if(x!=str[i]) check=0;
        i++;
    }
    if(!isEmpty(s1)) check=0;
    if(check)
        printf("YES, It is in (w.w-reverse) form\n");
    else
        printf("NO, It is not in (w.w-reverse) form\n");
    return 0;

}

//STACK IMPLEMENTATION IN C
STACK createStack(){
    STACK s;
    s.val[0]='\0';
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

