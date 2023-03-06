#include<stdio.h>
#include<stdlib.h>
typedef struct link
{
    int data;
    struct link *next;
}LINK;

void SetValueForNode(LINK *head)
{
    LINK *p = head->next;
    while (1)
    {
        puts("input data ");
        scanf("%d", &(p->data));
        if ((p = p->next) == NULL)break;
    }
}
    
void PrintNode(LINK *head) 
{
    LINK *p = head;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int ListDelete(int n,LINK *head)
{
    LINK *p = head,*temp;
    int i;
    if (n < 1|| n>head->data) return -1;
    for (i =1;i<= n-1;i++) p= p->next;  // 让p指向要被删除的前一位
    temp = p->next;
    p->next = p->next->next;
    free(temp);
    return 1;
}

LINK * IniList(LINK *head,int n)
{
    LINK *p;
    int i;
    head = (LINK *)malloc(sizeof(LINK));
    head ->data = n;   //头结点存储的数据为长度
    p = head;
    for (i=1;i<=n;i++)
    {
        p ->next= (LINK*)malloc(sizeof(LINK));
        p = p->next;
    }
    p = NULL;
    head ->data = n;
    return head;  // 返回创立的head内存地址
}

/* 算法 2-11   从表尾逆向建立至表头*/
LINK* InsertBeforeHead (int n, LINK *head )
{
    int i;
    head -> next =NULL;
    LINK *ptemp = NULL;
    for (i=0;i<n; i++)
    {
        int Data;
        printf("input data! ");
        scanf("%d", &Data);
        ptemp = head;
        head = (LINK*)malloc(sizeof(LINK));
        head ->data = Data;
        head ->next = ptemp; 
    }
    return head;
}

/*算法2-12*/
LINK * MergeList(LINK *ah,LINK *bh)
{
    LINK *ch = NULL;
    ch = IniList(ch, (ah->data+ bh->data));
    LINK *ap =ah->next, *bp = bh->next, *cp = ch->next;
    LINK *temp;
    do
    {
        if (ap->data <= bp->data)
        {
            cp ->data = ap->data;
            ap = ap->next;
        }
        else
        {
            cp ->data = bp->data;
            bp = bp->next;
        }
        temp = cp;
        cp = cp->next;
    }while (ap && bp);
    temp ->next  = ap? ap:bp;
    return ch;
}

int main()
{
    LINK *ah = NULL, *bh = NULL,*ch = NULL;
    ah= IniList(ah, 3);
    bh = IniList(ah,3);
    SetValueForNode(ah);
    SetValueForNode(bh);
    ch = MergeList(ah, bh);
    PrintNode(ch);
    return 0;
}

