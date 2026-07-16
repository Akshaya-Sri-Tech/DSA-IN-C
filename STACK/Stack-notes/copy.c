//Copies the contents of one stack into another stack

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
