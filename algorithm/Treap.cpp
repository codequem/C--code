/* 2023年2月3日15:45:41
完美。经过vs测试都是正确的 */
#include "Treap.h"
int q_prev_tmp = 0;
int q_nex_tmp = 0;

struct Treap_TreeNode
{
    ElementType val; //该节点存放的值，单独影响二叉查找树
    int rank;        //为了使其满足堆序性质而给出的单独属于堆的权值
    Treap Left;      //左子树
    Treap Right;     //右子树
    int rep_cnt;     //当前这个值(val)重复出现的次数
    int siz;         //以该节点为根的树的大小

    Treap_TreeNode(int val) : val(val), rep_cnt(1), siz(1) //初始化列表，好耶
    {
        Left = Right = nullptr;
        rank = rand();
        // 注意初始化的时候，rank 是随机给出的，必须随机，才能达到类似平衡树的效果
    }

    void upd_siz() // 用于旋转和删除过后，重新计算 siz 的值
    {
        siz = rep_cnt;
        if (Left != nullptr)
            siz += Left->siz;
        if (Right != nullptr)
            siz += Right->siz;
    }
};

static Position SingleRotateWithLeft(Position K2)
{
    Position K1; //先给定一个位置来做K2左子树，以便我们来进行操作（ 为什么不直接用K2->Left？
    //因为我们还得保证）
    K1 = K2->Left; //让这个临时节点来做K2左子树的根
    //以下的细节看图，还有:双旋转就是两次单旋转的结合，因此直接调用两次单旋转即可
    K2->Left = K1->Right;
    K1->Right = K2;
    K1->upd_siz(), K2->upd_siz(); //更新树的大小
    return K1;                    //新树的根
}

static Position SingleRotateWithRight(Position K2)
{
    Position K1;
    K1 = K2->Right;
    K2->Right = K1->Left;
    K1->Left = K2;
    K1->upd_siz(), K2->upd_siz(); //更新树的大小
    return K1;
}

void Insert(ElementType X, Treap &T)
{
    if (T == nullptr)
    {
        T = new Treap_TreeNode(X); //没这个节点直接新建
        return;
    }
    else if (X == T->val)
    {
        T->siz++; //如果有这个值相同的节点，就把重复数量加一
        T->rep_cnt++;
    }
    else if (X < T->val)
    {
        Insert(X, T->Left);
        if (T->Left->rank < T->rank)     // 小根堆中，上面节点的优先级一定更小，因为新插的左子节点比父节点小，现在需要让左子节点变成父节点
            T = SingleRotateWithLeft(T); //把小的点转上去
        T->upd_siz();                    //更新节点大小
    }
    else
    {
        Insert(X, T->Right);
        if (T->Right->rank < T->rank)
            T = SingleRotateWithRight(T); //把小的点转上去
        T->upd_siz();
    }
}

void Delete(ElementType X, Treap &T)
{
    if (X > T->val)
    {
        Delete(X, T->Right);
        T->upd_siz();
    }
    else if (X < T->val)
    {
        Delete(X, T->Left);
        T->upd_siz();
    }
    else
    {
        if (T->rep_cnt > 1)
        {
            T->rep_cnt--;
            T->siz--;
            return;
        }
        uint8_t state = 0;                     //确定这个要删的节点的儿子是怎么样的
        state |= (T->Left != nullptr);         // state的最低位表示左子树的有无，1为有，0为无
        state |= ((T->Right != nullptr) << 1); // state的次低位表示右子树的有无，同上
        // 00都无，01有左无右，10，无左有右，11都有
        Treap temp = T;
        switch (state)
        {
        case 0:
            delete T;
            T = nullptr;
            break;
        case 1:
            T = temp->Left; //把根变成左儿子，然后把原来的根节删了，注意这里的temp是从T复制的,而 T是引用
            delete temp;
            break;
        case 2:
            T = temp->Right;
            delete temp;
            break;
        case 3:
            if (T->Left->rank < T->Right->rank)
            {
                T = SingleRotateWithLeft(T); //将对的优先级的点转上来
                Delete(X, T->Right);
                T->upd_siz();
            }
            else
            {
                T = SingleRotateWithRight(T);
                Delete(X, T->Left); //追着删
                T->upd_siz();
            }
            break;
        }
    }
}

int query_rank(ElementType X, Treap T)
{
    int less_siz = (T->Left == nullptr) ? 0 : T->Left->siz; // 这个树中小于 val 的节点的数量
    if (X == T->val)
        return less_siz + 1; //如果这个节点就是要查的节点
    else if (X < T->val)
    {
        if (T->Left != nullptr)
            return query_rank(X, T->Left);
        else
            return 1; // 如果左子树是空的，说比最小的节点还要小，那这个数字就是最小的
    }
    else
    {
        if (T->Right != nullptr)
            // 如果要查的值比这个节点大，那这个节点的左子树以及这个节点自身肯定都比要查的值小
            // 所以要加上这两个值，再加上往右边找的结果（以右子树为根的子树中，val这个值的大小的排名）
            return less_siz + T->rep_cnt + query_rank(X, T->Right);
        else
            return T->siz + 1;
        // 没有右子树的话直接整个树 + 1 相当于 less_siz + T->rep_cnt + 1
    }
}

ElementType query_val(int rank, Treap T)
{
    int less_siz = (T->Left == nullptr) ? 0 : T->Left->siz; //即左子树大小
    if (rank <= less_siz)
        return query_val(rank, T->Left);
    else if (rank <= less_siz + T->rep_cnt)
        return T->val;
    else
        return query_val(rank - less_siz - T->rep_cnt, T->Right);
}

int query_prev(Treap T, ElementType X)
{
    if (X <= T->val)
    {
        if (T->Left != nullptr)
            return query_prev(T->Left, X);
    }
    else
    {
        q_prev_tmp = T->val;
        if (T->Right != nullptr)
            query_prev(T->Right, X);
        return q_prev_tmp;
    }
    return -114514;
}

int query_nex(Treap T, ElementType X)
{
    if (X >= T->val)
    {
        if (T->Right != nullptr)
            return query_nex(T->Right, X);
    }
    else
    {
        q_nex_tmp = T->val;
        if (T->Left != nullptr)
            query_nex(T->Left, X);
        return q_nex_tmp;
    }
    return -114514;
}