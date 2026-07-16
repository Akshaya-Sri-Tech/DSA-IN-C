//Copies the contents of one stack into another stack

//PRE-REQUISITES TO USE THE COPY FUNCTION
#define MAX_SIZE 10
typedef struct{
    int val[MAX_SIZE];
    int top;
}STACK;
typedef enum{ FALSE,TRUE }BOOL;
STACK createStack();


// COPY LOGIC :

BOOL copy(STACK *s1,STACK *s2){
    STACK s3;
    s3=createStack();
    while(!isEmpty(*s1)){
        int x;
        pop(s1,&x);
        push(&s3,x);
    }
    while(!isEmpty(s3)){
        int x;
        pop(&s3,&x);
        push(s1,x);
        push(s2,x);
    }
}
