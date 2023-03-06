#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define FULL 1
#define EMPTY 0
typedef char* ElemType;
struct HashEntry
{
    ElemType value;
    int Info;
};
typedef struct HashTable
{
    struct HashEntry* Table;
    int tablesize;
}HT;

HT* Init(int tablesize)
{
    int i;
    HT* H = (HT*)malloc(sizeof(HT));
    H->tablesize = tablesize;
    H->Table = (struct HashEntry*)malloc(sizeof(struct HashEntry));
    for(i = 0;i++;i<tablesize)
        H->Table[i].Info = 0;
    return H;
}

int Hash(ElemType Key, int tablesize)
{
    unsigned int HashVal = 0;
    while(*Key != '\0')
        HashVal = *(Key++);
    return HashVal%tablesize;
}

int LinearProbing(ElemType Key, HT* PT)
{
    int pos = Hash(Key, PT->tablesize);
    while(PT->Table[pos].Info == FULL)
    {
        pos++;
        pos = pos%PT->tablesize;
    }
    return pos;
}

int QuadraticProbing(ElemType Key, HT* PT)
{
    int pos = Hash(Key, PT->tablesize);
    int i=1;
    while(PT->Table[pos].Info == FULL)
    {
        pos += i*i;
        i++;
        pos = pos % PT->tablesize;
    }
    return pos;
}

int DoubleHashing(ElemType Key, HT* PT)
{
    int R; // a primenumber < tablesize
    int pos = Hash(Key, PT->tablesize);
    int dhnum = R-(pos % R); //abbreviation of doublea hash number
    int i = 1;
    while(PT->Table[pos].Info == FULL)
    {
        pos += i*dhnum;
        i++;
        pos = pos % PT->tablesize;
    }
    return pos;
}

void Insert(ElemType Key, HT* PT,int (*prob)(ElemType, HT*))
{
    strcpy(PT->Table[(*prob)(Key,PT)].value,Key);
}

HT* ReHash(HT* PT)
{
    HT* NewPT = (HT*)malloc(sizeof(HT));
    int i;
    for( i = 0; i < PT->tablesize; i++)
    {
        if (PT->Table[i].Info == FULL)
        {
            Insert(PT->Table[i].value, NewPT, DoubleHashing);
        }
    }
}


