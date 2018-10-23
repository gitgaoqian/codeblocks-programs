//平衡二叉树接口
#define TREE_TYPE char //定义二叉树存储的数据类型
typedef struct BIT_NODE
{
    TREE_TYPE data;
    int bf;//相比二叉树,增加BF因子
    struct BIT_NODE *lchild;
    struct BIT_NODE *rchild;
} BITNode, *BITree;
//链式二叉树
void R_Rotation(BITree *T)//传入最小非平衡树的根节点
{
    BITree L;
    L=(*T)->lchild;
    (*T)->lchild=L->rchild;
    L->lchild=(*T);
    *T=L;
}

void CreateTree(BITree &T);
TREE_TYPE * Find(BITree T,TREE_TYPE value);
//递归实现遍历二叉树的接口,参数为指向结点的指针
void Preorder(BITree T);
void Inorder(BITree T);
void Postorder(BITree T);
//利用栈实现非递归遍历二叉树
void IteraPreorder(BITree T);
void IteraInorder(BITree T);
//利用队列实现层序遍历
void Sequence(BITree T);

//查找,插入和删除操作,建立在树是有序树的基础上
bool Search(BITree T,TREE_TYPE value);
void Insert(BITree *T,TREE_TYPE value);
void Delete(BITree T,TREE_TYPE value);
void DeleteNode(BITree *p);

