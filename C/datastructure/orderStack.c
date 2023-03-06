#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct OrderStack
{
    int *base;
    int *top;
    int stacksize;
}SqStack;
void Init(SqStack *pst)
{
    pst->base = (int*)malloc(sizeof(MAX_SIZE));
    pst->top = pst->base;
    pst->stacksize= 0;
} 
void Push(SqStack *pst, int num)
{
    pst->top ++;
    *(pst->top) = num;
    pst->stacksize ++;
}
    
int Pop(SqStack *pst)
{
    pst->top --;
    pst->stacksize --;
    return *(pst->top+1);
}

