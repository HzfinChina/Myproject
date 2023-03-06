#include<stdlib.h>
#include<stdio.h>
#define MAX 10
typedef struct circlequeue
{
    int a[MAX] ;
    int head;
    int rear;
    int flag;  //0 为初始化阶段，没有填充数据，1已经填充了数据，2为已经满了 
}CirQ;

void Init(CirQ *pQ)
{
    pQ->head = 0;
    pQ->rear = 0;
    pQ->flag = 0;
}

void Insert(CirQ *pQ, int num)
{
    if (pQ->flag == 2) //此为已满情况
    {
        printf("No enough space");
        return;
    }
    if (pQ->flag == 0) //此为初始化情况
    {
        pQ->a[pQ->head] = num;
        pQ->flag = 1;
        return;
    }
    else   //此为初始化后情况
    {
       if(pQ->rear == 9)  //判断尾指针是否到达数组末尾
           pQ->rear = 0;
       else pQ->rear ++;  //若没有到达则尾指针后移插入元素
       if(pQ->rear-pQ->head == 0 ||pQ->head - pQ->rear == 1) //判断队列已满的条件：头和尾正好衔接
           pQ->flag = 2;
       pQ->a[pQ->rear] = num;
    }
}
int Delete(CirQ *pQ)
{
    int prevpos;
    if (pQ->flag == 0)
    {
        printf("this is a empty queue");
        return -1;
    }
    if (pQ->flag == 1)
    {
        pQ->flag =0;
        return pQ->a[pQ->head];
    }
    prevpos = pQ->head;
    pQ->head = pQ->head == 9? 0:pQ->head+1;
    return pQ->a[prevpos];
}

int main()
{
    CirQ *pQ;
    int i;
    pQ = (CirQ*)malloc(sizeof(CirQ));
    Init(pQ);
    for (i = 1;i<100;i*=2)
        Insert(pQ, i);
    while((i = Delete(pQ)) != -1)
        printf("%d\n",i);
    return 0;
}


