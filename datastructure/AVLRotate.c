Tree *SingleRotateLeft(Tree *preroot)  //此为平衡性被改变的那一点
{
    Tree *nowroot =preroot->left;
    preroot->left =preroot->left->right;
    nowroot->right = preroot;
    preroot->height = MAX(GetHeight(preroot->left),GetHeight(preroot->right))+1;
    nowroot->height = MAX(GetHeight(nowroot->left),GetHeight(nowroot->right))+1;
    return nowroot;
}

Tree *SingleRotateRight(Tree *preroot)
{
    Tree *nowroot = preroot->right;
    preroot->right = nowroot->left;
    nowroot->left = nowroot;
    preroot->left->height = MAX(GetHeight(preroot->left),GetHeight(preroot->right))+1;
    nowroot->height = MAX(GetHeight(nowroot->left),GetHeight(nowroot->right))+1;
    return nowroot;
}
/*插入的结点在当前结点的左结点的右结点下，改变了当前结点的平衡性
 * 首先对当前结点的左结点右旋转
 * 然后对当前结点左旋转*/
Tree *DoubleRotateLeftRight(Tree *preroot) 
{
    preroot->left = SingleRotateRight(preroot->left);
    preroot = SingleRotateLeft(preroot);
    return preroot;
}

/*插入的结点在当前结点的右结点的左结点下，改变了当前结点的平衡性
 * 首先对当前结点的右结点左旋转
 * 然后对当前结点右旋转*/
Tree *DoubleRotateRightLeft(Tree *preroot)
{
    preroot->right = SingleRotateLeft(preroot->right);
    preroot = SingleRotateRight(preroot);
    return preroot;
}
