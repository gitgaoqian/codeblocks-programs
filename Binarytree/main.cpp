#include <stdio.h>
#include "binarytree.h"
#include <iostream>
#include <unistd.h>
using namespace std;
int main()
{
    BITree T;
    CreateTree(T);
//    cout << '\n'<<"Preorder output:" <<endl;
//    Preorder(T);
//    cout << '\n'<<"Inorder output:" <<endl;
//    Inorder(T);
//    cout << '\n'<<"IteraPreorder output:" <<endl;
//    IteraPreorder(T);
//    cout << '\n'<<"IteraInorder output:" <<endl;
//    IteraInorder(T);
//    cout << '\n'<<"Sequence output:" <<endl;
//    Sequence(T);
    cout << '\n'<<"Preorder Output:" <<endl;
    Preorder(T);
    int leaf_count = LeafCount(T);
    cout << '\n'<<"leaf number:"<< leaf_count << endl;
    int th = TreeHigh(T);
    cout << "tree hight:"<< th << endl;
//    cout << '\n'<<"Serach:"<<endl;
//    Search(T,'H');
//    Search(T,'B');
//    Search(T,'K');
//    Search(T,'Q');
//
//    Insert(&T,'C');
//    Insert(&T,'P');
//    Insert(&T,'M');
//    Insert(&T,'R');
//    cout << '\n'<<"After Insert,Preorder output:" <<endl;
//    Preorder(T);
//    Delete(T,'P');
//    cout << '\n'<<"After Delete,Preorder output:" <<endl;
//    Preorder(T);

}
