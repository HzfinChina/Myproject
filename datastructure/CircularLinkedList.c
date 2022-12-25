#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int data; 
    struct link * next;
}LINK;

LINK * Init(LINK *head,int n)
{
    int i;
    LINK *p;
    head = (LINK*)malloc(sizeof(LINK));
    p = head;
    for (i=1;i<= n-1;i++)
    {
        p->next = (LINK*)malloc(sizeof(LINK));
        p = p->next;
    }
    p->next = head;
    return head;
}

/* 将b链表接到a链表后面*/
LINK *Merge(LINK *ah, LINK *bh)
{
    LINK *ap = ah->next, *bp = bh->next;
    while (ap ->next !=ah)ap = ap->next;
    while (bp->next !=bh)bp = bp->next;
    ap ->next = bh;
    bp ->next = ah;
    return ah;
}
void Appenddata(LINK *head)
{
    LINK *p =head;
    do
    {
        puts("input data");
        scanf("%d",&(p->data));
        p = p->next; 
    }while(p!=head);
}
void PrintNode (LINK *head)
{
    LINK *p = head;
    do
    {
        printf("%d\n",p->data);
        p = p->next;
    }while(p !=head);
}

int main()
{
    LINK *ah, *bh;
    ah = Init(ah,3);
    bh = Init(bh,3);
    Appenddata(ah);
    Appenddata(bh);
    Merge(ah, bh);
    PrintNode(ah);
}
