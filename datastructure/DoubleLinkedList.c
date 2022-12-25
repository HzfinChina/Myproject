#include<stdio.h>
#include<stdlib.h>

//创立双向循环链表
typedef struct doublelinklist
{
    int data;
    struct doublelinklist *pre;
    struct doublelinklist *next;
}LINK;

void SetValueForNode(LINK *head)
{
    LINK *p = head->next;
    while (1)
    {
        puts("input data ");
        scanf("%d", &(p->data));
        if ((p = p->next) == head)break;
    }
}

LINK * IniList(LINK *head,int n)
{
    int i;
    LINK *p ;
    head = (LINK*)malloc(sizeof(LINK));
    head ->data = n;
    p = head;
    for (i=1;i<= n;i++)
    {
        p->next = (LINK*)malloc(sizeof(LINK));
        p->next ->pre = p;
        p = p->next;
    }
    p->next = head;
    head->pre = p;
    return head;  // 返回创立的head内存地址
}

/* 在双向循环链表第i 个位置前插入元素*/
void  InsertNode(LINK *head,int i,int dat)
{
    LINK *insert = (LINK*)malloc(sizeof(LINK));
    insert -> data = dat;
    LINK *p = head, *pp;
    int k;
    for (k=1;k <= i-1;k++) p = p->next;  // 让p指向第i个位置的前一个元素
    pp = p->next;  //让pp指向第i个位置的元素 
    p ->next = insert;
    pp ->pre = insert;
    insert ->pre = p;
    insert ->next =pp;
}

void PrintNode(LINK *head) 
{
    LINK *p = head->next;
    while (p !=head)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void DeleteNode(LINK *head,int i)
{
    int k;
    LINK *p =head;
    for (k=1;k <= i;k++) p = p->next;  // 让p指向第i个位置的元素
    p->pre->next = p->next;
    p->next->pre = p->pre;
    free(p);
}
int main()
{
    LINK *head;
    head = IniList(head,2);
    SetValueForNode(head);
    InsertNode(head,1,5);
    PrintNode(head);
    DeleteNode(head,1);
    PrintNode(head);
}


