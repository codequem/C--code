int BinSearch_Cur(SSTable ST, KeyType key, int low, int high)
{
    if (low > high)
        return 0;
    else
    {
        int mid = (low + high) / 2;
        if (ST.R[mid] == key)
            return mid;
        else if (key < ST.R[mid])
            return BinSearch_Cur(ST, key, low, mid - 1);
        else
            return BinSearch_Cur(ST, key, mid + 1, high);
    }
}

void JudgeBST(BiTree T, int& flag) {
    if (T != NULL && flag) {
        JudgeBST(T->lchild, flag); // 中序遍历左子树
        if (pre == NULL)
            pre = T; // 中序遍历的第一个节点不必判断
        else if (pre->data < T->data)
            pre = T; // 前驱指针指向当前结点
        else
            flag = 0; // 不是二叉排序树
        JudgeBST(T->rchild, flag); // 中序遍历右子树
    }

}