#include "stdio.h"
#include "stdlib.h"
#define HASHSIZE 7 //定义散列表长,动态数组的最大长度?
#define NULLKEY -1
typedef struct{
    int *elem;//动态数组首地址
    int count; //当前动态数组的元素个数
}HashTable;
//对哈希表进行初始化
void Init(HashTable *hashTable){
    int i;
    hashTable->elem= (int *)malloc(HASHSIZE*sizeof(int));
    hashTable->count=HASHSIZE;
    for (i=0;i<HASHSIZE;i++){
        hashTable->elem[i]=NULLKEY;
    }
}
//哈希函数(除留余数法),用来进行散列地址的构造
int Hash(int data){
    return data%HASHSIZE;
}
//哈希表的插入函数，可用于构造哈希表
void Insert(HashTable *hashTable,int data){
    int hashAddress=Hash(data); //求哈希地址
    //发生冲突
    while(hashTable->elem[hashAddress]!=NULLKEY){
        //利用开放定址法解决冲突
        hashAddress=(++hashAddress)%HASHSIZE;
    }
    hashTable->elem[hashAddress]=data;
}
//哈希表的查找算法
int Search(HashTable *hashTable,int data){
    int hashAddress=Hash(data); //求哈希地址
    while(hashTable->elem[hashAddress]!=data){//发生冲突
        //利用开放定址法解决冲突
        hashAddress=(++hashAddress)%HASHSIZE;
        //如果查找到的地址中数据为NULL，或者经过一圈的遍历回到原位置，则查找失败
        if (hashTable->elem[hashAddress]==NULLKEY||hashAddress==Hash(data)){
            return 0;
        }
    }
    return 1;
}
int main(){
    int i,result;
    HashTable hashTable;
    int arr[HASHSIZE]={13,29,27,28,26,30,38};
    //初始化哈希表
    Init(&hashTable);
    //利用插入函数构造哈希表
    for (i=0;i<HASHSIZE;i++){
        Insert(&hashTable,arr[i]);
    }
    //调用查找算法
    result= Search(&hashTable,30);
    if (result==0) printf("search failed\n");
    else printf("search success\n");
    return  0;
}
