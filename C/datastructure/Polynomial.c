#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
    float coef;  //系数
    int expn;    //指数
}Elem;

typedef struct link
{
    Elem data;
    struct link* next;
}LINK;

LINK *Init()
{
    LINK *head = (LINK *) malloc(sizeof(LINK));
    int exp, flag;
    float coe;
    LINK * p = head;
    puts("input the polynomial");
    while(1)
    {
        if ((flag = scanf("%f %d " ,&coe, &exp)) != 2)break;
        p->next = (LINK* )malloc(sizeof(LINK));
        p = p->next;
        p ->data.coef = coe;
        p ->data.expn = exp;
    }
    return head;
}

void Print(LINK *head)
{
    LINK *p = head->next;
    while(p != NULL)
    {
        if (p->data.coef>0) printf(" +%.3fx^(%d)", p->data.coef, p->data.expn);
        else printf(" %.3fx^(%d)", p->data.coef, p->data.expn);
        p = p->next;
    }
}

LINK* Add(LINK *ah, LINK *bh)
{
    LINK *ch = (LINK*)malloc(sizeof(LINK));
    LINK *pa = ah->next, *pb = bh->next, *pc = ch;
    while( pa != NULL && pb != NULL)
    {
        pc -> next = (LINK*)malloc(sizeof(LINK));
        pc = pc->next;
        if (pa->data.expn > pb->data.expn)
        {
            pc->data = pa->data;
            pa = pa->next;
        }
        if (pa ->data.expn <pb->data.expn)
        {
            pc ->data = pb->data;
            pb = pb->next;
        }
        else 
        {
            pc ->data.coef = pa->data.coef+ pb->data.coef;
            pc ->data.expn = pa->data.expn;
            pa = pa->next;
            pb = pb->next;
        }
    }
    return ch;
}

LINK * Multiply(LINK *ah ,LINK *bh)
{
    LINK * resulth = (LINK*)malloc(sizeof(LINK));
}


void* Delete(LINK*head)
{
    LINK *ph = head, *ptemp;
    while(ph != NULL)
    {
        ptemp = ph;
        ph = ph->next;
        free (ptemp);
    }
}

int main()
{
    LINK *ah = NULL, *bh = NULL, *ch = NULL;
    ah = Init ();
    while(getchar() != '\n');
    bh = Init ();
    ch = Add(ah, bh);
    Print(ch);
}
        

        
    


