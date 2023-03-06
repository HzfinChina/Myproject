#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct num{
    short digit;
    short digitnum;
    struct num * next;
    struct num * prev;
};
typedef struct num *ptnum;

int powi(int base, int exponent){
    int retnum = 1;
    int i;
    for (i = 0; i < exponent; i++){
        retnum *= base;
    }
    return retnum;
}

void InsertAfter(ptnum pt, short digit, short digitnum){
    ptnum newptn = malloc(sizeof(struct num));
    newptn -> digit = digit;
    newptn -> digitnum = digitnum;
    newptn -> next = pt -> next; 
    newptn -> prev = pt;
    if (pt -> next) // if pt-> next is not NULL
        pt -> next->prev = newptn;
    pt -> next = newptn;
}

void InsertBefore(ptnum nownode){
    ptnum insertnode = malloc(sizeof(struct num));
    memset(insertnode, 0, sizeof(struct num));
    nownode->prev->next = insertnode;
    insertnode->next = nownode;
    insertnode->prev = nownode->prev;
    nownode -> prev = insertnode;
}


// the node whose digitnum is bigger than 10
void FullDecimal(ptnum pt){
    ptnum prevpos;
    short nownum, overflow;
    if (pt -> digitnum < 10)
        return;
    // if there is no node whose digit is one bigger than now
    // create a new one
    if (pt -> prev -> digit != pt->digit + 1){
        InsertBefore(pt);
        prevpos = pt->prev;
        prevpos -> digit = pt->digit + 1;
    }
    else // nownode->prev->digit is exactly one bigger than nownode;
        prevpos = pt->prev;
    nownum = pt->digitnum % 10;
    overflow = pt->digitnum / 10;
    pt->digitnum = nownum;
    pt->prev->digitnum += overflow;
    FullDecimal(pt->prev);
}

// assume has head node;
ptnum Plus(ptnum pt1, ptnum pt2){
    ptnum ptret = malloc(sizeof(struct num));
    ptnum ptmemory = ptret;
    while(pt1->next && pt2->next){
        if (pt1->next->digit > pt2->next->digit){
            pt1 = pt1->next;
            InsertAfter(ptret, pt1->digit, pt1->digitnum);
            ptret = ptret->next;
        }
        else if (pt1->next->digit < pt2->next->digit){
            pt2 = pt2->next;
            InsertAfter(ptret, pt2->digit, pt2->digitnum);
            ptret = ptret->next;
        }
        // has same digit, plus the digit num
        else {
            pt1 = pt1->next;
            pt2 = pt2->next;
            InsertAfter(ptret, pt1->digit, pt1->digitnum + pt2->digitnum);
            ptret = ptret->next;
            // 满十进位
            if (ptret->digitnum > 10) 
                FullDecimal(ptret);
        }
    }
    return ptmemory;
}

ptnum Multiply(ptnum pt1, ptnum pt2){
    
}

ptnum Initiate(const char * num){
    int i;
    const char * numhead = num;
    ptnum head = malloc(sizeof(struct num));
    ptnum retpointer = head;
    for (;*(++num)!= '\0';);
    for (i = 1;num != numhead;i++){
        InsertAfter(head, i, *(--num) -'0');
    }
    return retpointer;
};

void PrintNum(ptnum pbignum){
    while(pbignum->next){
        printf("%d",pbignum->next->digitnum);
        pbignum = pbignum->next;
    }
}

int main()
{
    ptnum anum = Initiate("5678198765126478596543524876230519427831245");
    ptnum another = Initiate("5678987654345678");
    ptnum ret = Plus(anum, another);
    PrintNum(ret);
}
