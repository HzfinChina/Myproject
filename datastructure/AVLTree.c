#include<stdio.h>
#include<stdlib.h>
typedef struct Avlnode
{
    int elem;
    struct Avlnode*left;
    struct Avlnode*right;
    short int height;
}Tree;
short int GetHeight(Tree *root)
{
    if (root == NULL)return -1;
    else return root->height;
}
Tree *Find(Tree *root, int num)
{
    Tree * temp = root;
    while(root!=NULL)
    {
        if (num>root->elem)
        {
            root = root->right;
            continue;
        }
        if (num<root->elem)
        {
            root = root->left;
            continue;
        }
        if (num == root->elem)
        {
            break;
        }
    }
    return root;
}
#define MAX(a,b) (a)>(b)?(a):(b)
#include "AVLRotate.c"

Tree *Insert(Tree *root, int num)
{
    if (Find(root, num) != NULL)return NULL;
    if (root==NULL)
    {
        root = (Tree*)malloc(sizeof(Tree));
        root->elem = num;
        root->left=NULL;root->right = NULL;
        root->height = 0;
    }
    else
    {
        if(num>root->elem)
        {
            root->right = Insert(root->right, num);
            if (GetHeight(root->right)-GetHeight(root->left)==2)
            {
                if (num > root->right->elem)
                    root = SingleRotateRight(root);
                else 
                    root = DoubleRotateRightLeft(root);
            }
        }
        if (num<root->elem)
        {
            root->left = Insert(root->left, num);
            if (GetHeight(root->left)-GetHeight(root->right) == 2)
            {
                if (num<root->left->elem)
                    root = SingleRotateLeft(root);
                else
                    root = DoubleRotateLeftRight(root);
            }
        }
    }
    root->height = MAX(GetHeight(root->left),GetHeight(root->right))+1;
    return root;
}

