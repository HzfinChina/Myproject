#include<stdio.h>
#include<stdlib.h>
/*
 * 建立两个结构体，其中一个LINK 是一个循环链表（便于Pop操作）
 * 另一个是OrderStack，base是头指针，top 是尾节点
 */
typedef struct Link
{
    int elem;
    struct Link *next;
    struct Link *prev;
}LINK;
typedef struct OrderStack
{
    int stacksize;
    LINK *base;
    LINK *top;
}SqStack;

void InitStack(SqStack *pst)
{
    pst->stacksize = 0;
    pst->base = (LINK*)malloc(sizeof(LINK));
    pst->top = pst->base;  //将让初始时头指针等于尾节点
    pst->base->prev = NULL;
    pst->base->next = NULL;
}

void Push(SqStack *pst)
{
    pst->stacksize ++;
    pst->top->next = (LINK*)malloc(sizeof(LINK));
    pst->top->next->prev = pst->top;
    pst->top->next->next = NULL;
    pst->top = pst->top->next;
    puts("input number you want to push in");
    scanf("%d",&pst->top->elem);
}

void Pop(SqStack *pst)
{
    if (pst->stacksize == 0)
    {
        puts("empty stack!");
        return;
    }
    printf("%d\n",pst->top->elem);
    pst->top = pst->top->prev;
    free(pst->top->next);
    pst->top->next = NULL;
}

        
        
