//reference:https://www.jianshu.com/p/eb554b0943ab    http://c.biancheng.net/view/568.html

#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

void Print(int elem)
{
    cout << elem << " " ;
}
int Unary(int elem)
{
    return elem*elem;
}
int Binary(int lelem,int relem)
{
    return lelem + relem;
}
bool Pred(int elem)
{
    return elem < 40;
}
bool Search_Pred(int v1_elem,int v2_elem)
{
    return v1_elem < v2_elem;
}
bool Replace_Pred(int elem)
{
    return elem < 70;
}
int main()
{

   vector<int> v;
   v.reserve(20);//设置保留容量即v.capacity()
   vector<int>::iterator s;
   vector<int>::iterator e;
   for(int i=0;i<10;i++)
        v.push_back((rand() % (100))+ 0);
    v.insert(v.begin()+2,138);
    s = v.begin();
    e = v.end();
    cout << "print v:";
    for_each(s,e,Print);
    //最大最小
    cout << "min: "<<*min_element(s,e) << endl;
    cout << "----------------TRANSFORM-------------"<<endl;
    //transform的一元操作
    vector<int> vt(v);
    transform(s,e,vt.begin(),Unary);
    cout << "transformed unary, print vt:";
    for_each(vt.begin(),vt.end(),Print);
    cout << endl;
    //transform的二元操作
    vector<int> vt2(v);
    transform(s,e,vt.begin(),vt2.begin(),Binary);
    cout << "transformed binary, print vt2:";
    for_each(vt2.begin(),vt2.end(),Print);
    cout << endl;
    cout << "---------------------SORT----------------------"<<endl;
    //排序
    sort(s,e);
    cout << "print v after sort:";
    for_each(s,e,Print);
    cout << endl;

    //反转和旋转
    reverse(s,e);
    cout << "print v after reverse:";
    for_each(s,e,Print);
    cout << endl;
    rotate(s,s+4,e);
    cout << "print v after rotate:";
    for_each(s,e,Print);
    cout << endl;
    cout << "----------------------FINDING-----------------------"<<endl;
    //判断容器中时候统计、查找、搜索、边界
    //统计
    cout << "22 in vector:" << count(s,e,22) << endl;
    cout << "less than 40 vector:"<< count_if(s,e,Pred)<<endl;
    /*注：有些算法会引入两个尾词：_if和_copy;
    尾部是_if：如果算法有两种形式，参数个数都相同，但是第一形式的参数要传递一个值；第二形式（加_if的）传递一个函数。
    尾部是_copy:表示在此算法中，元素不光被操作，还会被复制到目标区间*/

    //查找
    vector<int>::iterator vf;
    vf = find_if(s,e,Pred);
    cout <<"find first element less than 40 in v:"<< *vf << endl;
    //搜索：search不需要区间有序，二分搜索需要区间有序
    vector<int> v2{77,49};
    vector<int>::iterator vs;
    vs = search(s,e,v2.begin(),v2.end());
    if (vs != e)
        cout << "v2 first appered in v1:"<<*vs << endl;
    vs = search(s,e,v2.begin(),v2.end(),Search_Pred);
    if(vs!= e)
        cout << "v2 more than v1 first appear "<< *vs << endl;
    sort(s,e);
    if(binary_search(s,e,49))//二分算法需要在排序区间内操作
        cout << "49 in v" << endl;
    else
        cout << "49 not in v"<< endl;

    //边界：需要区间有序
    cout << "print v:";
    for_each(s,e,Print);
    cout << endl;
    v.insert(lower_bound(s,e,38),38);//lower_bound搜索第一个大于等于vlaue的
    e = v.end();//因为end()位置变了，所以e需要重新赋值
    v.insert(upper_bound(s,e,72),72);//upper_bound搜索第一个大于value的
    e = v.end();
    v.insert(equal_range(s,e,56).first,56);
    v.insert(equal_range(s,e,56).second,56);
    e = v.end();
    cout << "print v after insert:";
    for_each(s,e,Print);
    cout << endl;

    //删除和替换
    //复制
    vector<int> v_copy(v.size());
    copy(s,e,v_copy.begin());
    cout << "print v_copy:";
    for_each(v_copy.begin(),v_copy.end(),Print);
    cout << endl;

    //移除：remove常常与成员函数erase结合使用改变size
    vector<int> v_remove(v.size());
//    remove(s,e,56);//不改变size
//    for_each(v_remove.begin(),remove_copy(s,e,v_remove.begin(),93),Print);
//    cout << endl;
    v.erase(remove(s,e,56),v.end()); //remove返回开会重复打印的第一个位置
    cout << "print v after erase remove:";
    for_each(s,v.end(),Print);
    cout << endl;

    //替换
//    replace_if(s,e,Replace_Pred,88);
//    for_each(s,e,Print);
//    cout << endl;

    //去重:去除相邻重复的元素
    vector<int> v_unique(v.size());
    unique_copy(s,e,v_unique.begin());//清除相邻重复的元素；不改变size
    v_unique.erase(remove(v_unique.begin(),v_unique.end(),0),v_unique.end());
    cout << "print v_unique:";
    for_each(v_unique.begin(),v_unique.end(),Print);
    cout << endl;

    //交换
    cout << "-------------SWAP-------------------"<<endl;
    cout << "print v:";
    for_each(s,v.end(),Print);
    cout << endl;
    vector<int> v_swap(v.size());
    swap_ranges(v.begin(),v.end(),v_swap.begin());
    for_each(v.begin(),v.end(),Print);
    cout <<"v.size(),v.capacity():"<<v.size()<<","<<v.capacity()<< endl;
    cout << "print v_swap:";
    for_each(v_swap.begin(),v_swap.end(),Print);
    cout <<"v_swap.size(),v_swap.capacity():"<<v.size()<<","<<v_swap.capacity()<< endl;

    v.swap(v_swap);//利用成员函数swap改变容量
    cout <<"v.size(),v.capacity():"<<v.size()<<","<<v.capacity()<< endl;

    //算数算法
    cout << "-----------------NUMERIC--------------------" << endl;
    cout << "print v:";
    for_each(v.begin(),v.end(),Print);
    cout << endl;
    int val = accumulate(v.begin(),v.end(),0);
    cout << "sum of all elements in the vector:" << val << endl;
    vector<int> v_sum(v.size());
    partial_sum(v.begin(),v.end(),v_sum.begin());//当前元素值等于当前元素值和前面所有值之和
    vector<int> v_differ(v.size());
    adjacent_difference(v.begin(),v.end(),v_differ.begin());//当前元素等于当前元素减去前面元素
    cout << "print v_differ:";
    for_each(v_differ.begin(),v_differ.end(),Print);
    cout << endl;
    cout << "inner_product between v and v_differ:" << inner_product(v.begin(),v.end(),v_differ.begin(),0) << endl;//两个向量求内积

    /*关系算法*/
    cout << "-------------------LOGIC-----------------------"<< endl;
    if(equal(v.begin(),v.end(),v_differ.begin()))//判断两个向量的元素是否都相等
        cout << "v equal to v_differ"<< endl;
    if(includes(v.begin(),v.end(),v_differ.begin(),v_differ.end()))
        cout << "v includes v_differ"<< endl;
    cout << "the first different element between v and v_differ:";
    cout << *(mismatch(v.begin(),v.end(),v_differ.begin()).first) <<  " " << *(mismatch(v.begin(),v.end(),v_differ.begin()).second)<< endl;//并行比较两个向量，返回第一个不匹配的位置

    cout << "--------------------------SET ALGORITHM---------------------"<<endl;//求并集、交集、差集等等
    vector<int> vv{50,60,70,80,10,20,30,40};
    vector<int> v_merge(v.size()+vv.size());
    /*merge() 算法会合并两个序列并将结果保存到第三个序列中，它使用 < 运算符（重要）来比较元素；对于两个已序序列进行merge就是归并排序*/
    merge(v.begin(),v.end(),vv.begin(),vv.end(),v_merge.begin());
    for_each(v_merge.begin(),v_merge.end(),Print);
    cout<<endl;
    inplace_merge(vv.begin(),vv.begin()+4,vv.end());//合并同一个序列中两个有序的子列
    cout << "print vv:";
    for_each(vv.begin(),vv.end(),Print);
    cout<<endl;
    vector<int> v_union(v.size()+vv.size());
    set_union(v.begin(),v.end(),vv.begin(),vv.end(),v_union.begin());//求并集,操作符是“<”(重要)
    cout << "print set union:";
    for_each(v_union.begin(),v_union.end(),Print);
    cout << endl;
    /*-------------------------------排列组合算法--------------------------------------*/
    /*-------------------------------堆排序算法----------------------------------------*/

}
