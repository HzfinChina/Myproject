#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef char* ElemType;
struct Node
{
    ElemType value;
    struct Node *next;
};
typedef struct Node* List;
typedef struct HashTable
{
    int tablesize;
    List* TheLists;
}HT;

HT* Init(int size, struct HashTable* H)
{
    int i;
    H = (HT*)malloc(sizeof(HT));
    H->tablesize = size;
    H->TheLists = (List*)malloc(sizeof(List)*size);
    for(i=0;i<size;i++)
        H->TheLists[i] ->next =NULL;
    return H;
}

int Hash(ElemType Key, int Tablesize)
{
    unsigned int Hashvalue = 0;
    while (*Key != '\0')
        Hashvalue = *(Key++);
    return Hashvalue;
}

List Find(ElemType Key, HT* Table)
{
    int Hashvalue = Hash(Key, Table->tablesize);
    List Compare;
    while (Compare!=NULL)
        if (strcmp(Compare->value, Key) == 0)
            return Compare;
}

void Insert(ElemType Key, HT* Table)
{
    int Hashvalue = Hash(Key, Table->tablesize);
    if (Find(Key, Table) != NULL)
    {
        List position = Table->TheLists[Hashvalue];
        while (position->next != NULL)
            position = position->next;
        position->next = (List)malloc(sizeof(struct Node));
        position = position->next;
        position->value = Key;
        position->next = NULL;
    }
}


