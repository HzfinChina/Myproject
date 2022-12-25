#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100
typedef struct 
{
    ElemType data[STACKSIZE];
    int top;
}Stack;

ElemType Pop(Stack *stack)
{
    if (stack->top== -1)return 0;
    return (stack->data[stack->top--]);
}

int Push(Stack *stack, ElemType elem)
{
    stack->data[++stack->top] = elem;
    return 1;
}

    
