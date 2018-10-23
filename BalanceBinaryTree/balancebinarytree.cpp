//关于平衡二叉树学习内容比较复杂一点.尤其是左平衡和右平衡函数.没有掌握
//平衡二叉树接口
#define LH 1
#define EH 0
#define RH -1
#define TREE_TYPE char //定义二叉树存储的数据类型
typedef struct BIT_NODE
{
    TREE_TYPE data;
    int bf;//相比二叉树,增加BF因子
    struct BIT_NODE *lchild;
    struct BIT_NODE *rchild;
} BITNode, *BITree;
//右旋函数
void R_Rotation(BITree *T)//传入最小非平衡树,
{
    BITree L;
    L=(*T)->lchild;
    (*T)->lchild=L->rchild;
    L->rchild=(*T);
    *T=L;
}
// 左旋函数
void L_Rotation(BITree *T)//传入最小非平衡树,
{
    BITree R;
    R=(*T)->rchild;
    (*T)->rchild=R->lchild;
    R->lchild=(*T);
    *T=R;
}

void LeftBalance(BITree *T)//解决LL和LR型
{
    BITree L,Lr;
    L = (*T)->lchild;
    switch(L->bf)
    {
        case LH://右旋处理,LL型
            (*T)->bf=L->bf=EH;
            R_Rotation(T);
            break;
        case RH://根节点和左子树的符号不同,要先左旋再右旋,LR型
            Lr=L->rchild;
            switch(Lr->bf)
            {
                case LH:
                    (*T)->bf=RH;
                    L->bf=EH;
                    break;
                case EH:
                    (*T)->bf=L->bf=EH;
                    break;
                case RH:
                    (*T)->bf=EH;
                    L->bf=LH;
                    break;
            }
            Lr->bf=EH;
            L_Rotation(&(*T)->lchild);
            R_Rotation(T);

    }
}

void RightBalance(BITree *T)
{
    BITree R,Rl;
    R = (*T)->rchild;
    switch (R->bf)
    {
         case RH://右旋处理
            (*T)->bf=R->bf=EH;
            L_Rotation(T);
            break;
        case LH://根节点和左子树的符号不同,要先左旋再右旋
            Rl=R->lchild;
            switch(Rl->bf)
            {
                case RH:
                    (*T)->bf=LH;
                    R->bf=EH;
                    break;
                case EH:
                    (*T)->bf=R->bf=EH;
                    break;
                case LH:
                    (*T)->bf=EH;
                    R->bf=RH;
                    break;
            }
            Rl->bf=EH;
            R_Rotation(&(*T)->rchild);
            L_Rotation(T);

    }
}

