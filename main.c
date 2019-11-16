#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct {
    char value[MAXSIZE];
    int top;
}Stack_type;

typedef enum{true,false}boolean;

boolean is_Stack_Full(Stack_type *Stack){
    return (Stack->top==MAXSIZE-1);
}
boolean is_Stack_Empty(Stack_type *Stack){
    return (Stack->top==-1);
}
void push(Stack_type *Stack,int Value){
    if(!is_Stack_Full(Stack))
        Stack->value[++(Stack->top)]=Value;
    else
    printf("Error Stack is full\n");
}
int pop(Stack_type *Stack){
    return Stack->value[(Stack->top)--];
}
int size(Stack_type *Stack){
    return Stack->top;
}
int peek(Stack_type *Stack){
    return Stack->value[Stack->top];
}

int main()
{
    char infix[100];
    scanf("%s",infix);
    char postfix[100];
    Stack_type the_Stack;
    the_Stack.top=-1;
    int i=0,j=0;
    char optop;
    while(infix[i]!='\0'){
        switch (infix[i]){

        case '+':
        case '-':

            if(is_Stack_Empty(&the_Stack)){
                push(&the_Stack,infix[i]);
                break;
            }
            else{
                while(!is_Stack_Empty(&the_Stack)){
                    optop=pop(&the_Stack);
                    if(optop=='('){
                        push(&the_Stack,optop);
                        break;
                       }
                    else{
                        postfix[j]=optop;
                        j++;
                    }
                }
                push(&the_Stack,infix[i]);
                break;
            }

        case '*':
        case '/':
                  if(is_Stack_Empty(&the_Stack)){
                    push(&the_Stack,infix[i]);
                    break;
                  }
                  else{
                        optop=pop(&the_Stack);
                        if(optop=='('){
                            push(&the_Stack,optop);
                            push(&the_Stack,infix[i]);
                            break;
                       }
                       else{
                            if(optop=='+'||optop=='-'){
                                push(&the_Stack,optop);
                                push(&the_Stack,infix[i]);
                                break;
                            }
                            else{
                                postfix[j]=optop;
                                j++;
                                push(&the_Stack,infix[i]);
                                break;
                            }

                       }
                  }

        case '(':
                  push(&the_Stack,infix[i]);
                  break;

        case ')':
                  while(!is_Stack_Empty(&the_Stack)){
                    optop=pop(&the_Stack);
                    if(optop=='(')
                        break;
                    else
                        postfix[j]=optop;
                        j++;
                  }
                  break;

        default : postfix[j]=infix[i];
                  j++;
        }
        i++;
    }
    while(!is_Stack_Empty(&the_Stack)){
        postfix[j]=pop(&the_Stack);
        j++;
    }
    postfix[j]='\0';
    j=0;
    printf("\n%s\n\n",infix);
    printf("%s\n\n",postfix);
    Stack_type the_stack;
    the_stack.top=-1;
    int num1,num2;
    while(postfix[j]!='\0'){
        switch (postfix[j]){

        case '+':
               num2=pop(&the_stack);
               num1=pop(&the_stack);
               push(&the_stack,num1+num2);
               break;
        case '-':
               num2=pop(&the_stack);
               num1=pop(&the_stack);
               push(&the_stack,num1-num2);
               break;
        case '*':
               num2=pop(&the_stack);
               num1=pop(&the_stack);
               push(&the_stack,num1*num2);
               break;
        case '/':
               num2=pop(&the_stack);
               num1=pop(&the_stack);
               push(&the_stack,num1/num2);
               break;
        default :
               push(&the_stack,(int)(postfix[j]-'0'));
        }
        j++;
    }
    num1=pop(&the_stack);
    printf("%d\n",num1);
    return 0;
}
