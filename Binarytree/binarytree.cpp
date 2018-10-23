#include <iostream>
#include "binarytree.h"
#include <stdio.h>
#include <malloc.h>
#include<stack>
#include<queue>
using namespace std;
int leaf_count = 0;
int hight = 0;
//参考<大话数据结构>

void Insert(BITree *T,TREE_TYPE value)//如果树中不存在节点值value,那么插入节点,非递归方式实现的
{
    //判断树是否为空,若为空将该值作为根节点进行插入
    BITNode *I,*p,*fp;//I表示插入的节点,fp指向p的父节点,
    p = *T;
    while ( p!= 0)//找到插入的空位置
    {
        if (value == p->data)
        {
            printf("the value in the tree, can't insert again \n");
            return;
        }
        else if (value < p->data)
        {
            fp = p;
            p = p->lchild;
        }
        else
        {
            fp = p;
            p = p->rchild;

        }

    }
    I = (BITree)malloc(sizeof(BITNode));
    I->data = value;
    I->lchild = 0;
    I->rchild = 0;//插入操作,插入的结点只能作为叶节点.(因为只能在空的地方进行插入操作吧)
    if (fp->data > value)
        fp->lchild = I;
    else
        fp->rchild = I;

}

bool Search(BITree T, TREE_TYPE value)//递归查找,(改:返回一个父节点)
{
    if (!T)
    {
        printf("The value not in the tree \n");
        return false;
    }
    else if (T->data == value)
    {
        printf("The value in the tree \n");
        return true;
    }
    else if (T->data > value)
        return Search(T->lchild,value);
    else if (T->data < value)
        return Search(T->rchild,value);

}

void Delete(BITree T,TREE_TYPE value)//多看几遍
{
    BITree p;
    p = T;
    while ( p!= 0)//找到插入的空位置
    {
        if (value == p->data)
        {
            break;
        }
        else if (value < p->data)
        {
            p = p->lchild;
        }
        else
        {
            p = p->rchild;
        }

    }
    if (p == 0)
    {
        printf("the value not in the tree,can't delete");
        return;
    }
    DeleteNode(&p);//删除结点

}
void DeleteNode(BITree *p)
{
    BITree q,s;
    if ((*p)->rchild == 0)
    {
        q=*p;*p=(*p)->lchild;free(q);
    }
    else if ((*p)->lchild == 0)
    {
        q=*p;*p=(*p)->rchild;free(q);
    }
    else
    {
        q=*p;s=(*p)->lchild;
        while(s->rchild)//从该结点的左子树中找一个最大值,也就是这个左子树中的最下层的右子树结点
        {
            q=s;s=s->rchild;
        }
        (*p)->data=s->data;
        if (q!=*p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        free(s);

    }
}

void CreateTree(BITree &T) //因为我们传过来的是一个指向空的指针.如果形式参数参数还是指针类型(BITree T),那么形参的改变是不会改变原有指针的值,所以需要使用指针的指针或者指针的应用.//此处创建的树也是无序的,对于查找和删除的操作而言是基于有序树的.
{
	TREE_TYPE ch;
	scanf("%c",&ch);
	if (ch == '#')
        T = 0;
    else
    {

        T=(BITree)malloc(sizeof(BITNode));

        if (!T)
        {
            printf("分配空间失败");
        }
        T->data=ch;
        CreateTree(T->lchild);	//构造左子树
        CreateTree(T->rchild);	//构造右子树

    }

}

void Preorder(BITree T)
{

    if (T)//递归函数终止条件:T == null
    {
        printf("%c",T->data);
        Preorder(T->lchild);//可以理解为递去
        Preorder(T->rchild);//可以理解为归来
    }
}

void Inorder(BITree T)
{

    if (T)
    {
        Inorder(T->lchild);
        printf("%c",T->data);
        Inorder(T->rchild);

    }
}

void Postorder(BITree T)
{

    if (T)
    {
        Postorder(T->lchild);
        Postorder(T->rchild);
        printf("%c",T->data);

    }
}

void IteraPreorder(BITree T)//迭代实现遍历的原理是:用栈来实现递归,用循环代替选择
{
    if (T == 0)
		return;
	BITNode* p = T;//树的根结点的指针
	stack<BITNode*> s;//建立一个存储结点指针的栈
	while (!s.empty() || p)//二叉树结构中的左结点入栈,输出左结点,出栈输出右结点.
	{
		if (p)
		{
			cout << p->data;
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}


}

void IteraInorder(BITree T)
{
	//空树
	if (T == 0)
		return;
	//树非空
	BITNode* p = T;
	stack<BITNode*> s;
	while (!s.empty() || p)
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->data ;
			p = p->rchild;
		}
	}
}

void Sequence(BITree T)//层序不存在往返的,其比较适合以队列的方式来实现遍历.
{
    if (T==0)
        return;
    BITNode* p = T;
    queue<BITNode*> q;//建立一个存储结点指针的队列
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        cout << p->data;
        q.pop();
        if (p->lchild != 0)
        {
            q.push(p->lchild);
        }

        if (p->rchild != 0)
            q.push(p->rchild);
    }


}

int LeafCount(BITree T)
{
    if (T!=0)
    {
        if(T->lchild==0 && T->rchild==0)
            leaf_count++;
        LeafCount(T->lchild);
        LeafCount(T->rchild);
    }

    return leaf_count;


}
int TreeHigh(BITree T)
{
    if (T!=0)
    {
         if (T->lchild!=0 || T->rchild != 0)
    {
        hight++;
        TreeHigh(T->lchild);
        TreeHigh(T->rchild);
    }

    }
    return hight+1;

}
