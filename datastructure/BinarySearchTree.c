#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int elem;
    struct tree *left;
    struct tree *right;
}Tree;

Tree* Find(Tree *root, int num)
{
    if (root == NULL)return NULL;
    if(num>root->elem)
        return Find(root->right,num);
    if(num< root->elem)
        return Find(root->left,num);
    if (num == root->elem)
        return root;
}

Tree *FindMin(Tree *root)
{
    while(1)
    {
        root = root->left;
        if (root->left  == NULL)return root;
    }
}

Tree *FindMax(Tree *root)
{
    if (root->right!=NULL)
        return FindMax(root->right);
    if (root->right ==NULL)
        return root;
}

void Insert(Tree *root, int num)
{
    if (Find(root,num)!=NULL)return;
    Tree *node = (Tree*)malloc(sizeof(Tree));
    node->elem = num;
    node->left = NULL;
    node->right = NULL;
    while(1)
    {
        if(num>root->elem)
        {
            if(root->right == NULL)
            {
                root->right = node;
                break;
            }
            root = root->right;
            continue;
        }
        if (num<root->elem)
        {
            if (root->left == NULL)
            {
                root->left = node;
                break;
            }
            root = root->left;
            continue;
        }
    }
}

void Init(Tree *root)
{
    int i, num;
    root->elem = 1;
    root->left = NULL;
    root->right = NULL;
    for (i=2;i<=7;i++)
    {
        num = i;
        Insert(root, num);
    }
}


int main()
{
    Tree *root = (Tree*)malloc(sizeof(Tree));
    Init(root);
}
