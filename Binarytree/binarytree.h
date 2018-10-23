//二叉树接口
#define TREE_TYPE char //定义二叉树存储的数据类型:孩子表示法
typedef struct BIT_NODE
{
    TREE_TYPE data;
    struct BIT_NODE *lchild;
    struct BIT_NODE *rchild;
} BITNode, *BITree;
//链式二叉树

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

//查找,插入和删除操作,建立在树是二叉排序树的基础上
bool Search(BITree T,TREE_TYPE value);
void Insert(BITree *T,TREE_TYPE value);
void Delete(BITree T,TREE_TYPE value);
void DeleteNode(BITree *p);

//计算叶节点个数:先序遍历法
int LeafCount(BITree T);
//计算树的高度
int TreeHigh(BITree T);
