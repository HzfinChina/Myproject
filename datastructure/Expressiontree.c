#include<stdio.h>
#include<stdlib.h>
typedef struct BinaryTree
{
    char elem;
    struct BinaryTree *left;
    struct BinaryTree *right;
}Btree ;
typedef Btree* ElemType;
#include "arrayStack.c"

void Print(Btree* root)
{
    if (root->left != NULL) // 有子结点的一定是运算符
    {
        printf("(");
        Print(root->left);
        printf("%c",root->elem);
        Print(root->right);
        printf(")");
    }
    else 
        printf("%c",root->elem);
}

Btree* Input(char *str)
{
    char*ps = str;
    Btree* onenode;
    Stack stack;
    stack.top = -1;
    while(1)
    {
        onenode = (Btree*)malloc(sizeof(Btree));
        onenode->elem = *ps;
        if (*ps!='+'&&*ps!='-'&&*ps!='*'&&*ps!='/')
        {
            Push(&stack,onenode);
            onenode->left =NULL;
            onenode->right = NULL;
        }
        else
        {
            onenode->left = Pop(&stack);
            onenode->right = Pop(&stack);
            Push(&stack,onenode);
        }
        ps++;
        if (*ps == '\0')break;
    }
    return onenode;
}
int main()
{
    Btree* root =Input("ab+cde+**");
    printf("hello ");
    printf("world");
    return 0;
}

