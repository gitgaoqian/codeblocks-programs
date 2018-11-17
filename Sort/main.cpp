//排序是对顺序表的一种操作，我们定义顺序表以连续存储方式定义：
#define MAXSIZE 10 //用于要排序数组个数最大值
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>


typedef struct
{
    int r[MAXSIZE+1]; //这里利用的是静态数组
    int length; //记录顺序表的长度
}Sqlist;
void CreateList(Sqlist *L,int Size)
{
    int i ;
    for (i=0;i<Size;i++)
    {
        L->r[i] = rand()%100+1;
        (L->length)++;
    }

}
void PrintList(Sqlist *L)
{
     for (int i=0;i<L->length;i++)
        printf("%d\n",L->r[i]);
}
void Swap(Sqlist *L,int i,int j)//交换L中的数组下标为i和j的值
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void BubbleSort(Sqlist *L)//此处按照从小到大的顺序进行排列,
{
    int i,j;
    int flag = 1;//flag用来标记，来优化顺序
    for (i=0;i<L->length-1 && flag == 1;i++)
    {
        flag = 0;
        for (j=L->length-2;j>=i;j--)
        {
            if (L->r[j]>L->r[j+1])
            {
                Swap(L,j,j+1);
                flag = 1;
            }

        }
    }
}


void SimpleSelectSort(Sqlist *L)
{
    int i,j,Min;
    for(i=0;i<L->length-1;i++)
    {
        Min = i;
        for (j=i+1;j<L->length;j++)
        {
            if (L->r[Min]>L->r[j])
            {
                Min = j;
            }

        }
        if (i!= Min)
        {
            Swap(L,i,Min);
        }

    }

}


void StraightInsertionSort(Sqlist *L)
{
    int i,j,temp;
    for (i=1;i<L->length;i++)
    {
        temp = L->r[i];
        j=i-1;
        while ((j>=0)&&(L->r[j]>temp))
        {
            L->r[j+1] = L->r[j];
            j--;
        }
        L->r[j+1] = temp;
    }
}


//void ShellSort(Sqlist *L)
//{
//    int i,j,temp;
//    int gap;//希尔步长
//    for (gap=L->length/2;gap>0;gap=gap/2)//程序和直接插入排序相比就是多了步长的设置.
//    {
//        for(i=gap;i<L->length;i++)
//        {
//            temp = L->r[i];
//            j=i;
//            while ((j>0)&&(L->r[j-gap]>temp))
//            {
//                L->r[j] = L->r[j-gap];
//                j = j - gap;
//            }
//            L->r[j] = temp;
//        }
//
//    }
//
//}
void SHELLSORT(Sqlist *L,int gap)
{
    for(int i = gap; i < L->length; i++)
    {
        int temp = L->r[i];
        int j = i-gap;
        while((L->r[j] > temp) && (j>=0))
        {
            L->r[j+gap] = L->r[j];
            j = j - gap;

        }
        L->r[j+gap] = temp;

    }

}
void ShellSort(Sqlist *L)
{
    int gap = L->length/2;//设定步长初始值
    while(gap!=0)
    {
        SHELLSORT(L,gap);
        gap = gap / 2;
    }

}

void Merge(int SR[],int TR[],int i,int m,int n)//归并[i..m][m+1..n]两两归并一次
{
    int j,k,l;
    printf("i=%d,m=%d,n=%d\n",i,m,n);
    for(j=m+1,k=i;i<=m&&j<=n;k++)
    {
        if (SR[i] < SR[j])
            TR[k] = SR[i++];
        else
            TR[k] = SR[j++];
    }

    //处理归并前项和后项中没有插入到TR中的比较大的元素
    if (i<=m)
    {
        for (l=0;l<=m-i;l++)
        {
            TR[k] = SR[i+l];
            k++;
        }
    }

    if (j<=n)
    {
        for (l=0;l<=n-j;l++)
        {
            TR[k] = SR[j+l];
            k++;
        }

    }
    for (l=0;l<k;l++)//输出TR
    {
        //printf("k=%d,TR[k]=%d,TR[K+1]=%d\n",k,TR[k],TR[k+1]);
        printf("TR[%d]=%d\n",l,TR[l]);


    }

}
void MergePass(int SR[],int TR[],int s,int n)//将SR中相邻长度为s的子序列两两归并到TR
{
    int i=0;
    int j;
    while (i <= n-2*s)//
    {
        Merge(SR,TR,i,i+s-1,i+2*s-1);//归并函数,i+s-1表示归并前项末尾元素,i+2*s-1表示归并后项的末位元素
        i=i+2*s;
    }
    //处理序列剩下的部分
    if (i<n-s)//整个排序的最后一次合并,为啥是n-s+1?
        Merge (SR,TR,i,i+s-1,n-1);
    else
        for(j=i;j<=n;j++)
            TR[j] = SR[j];
    printf ("s=%d\n",s);
    for (int a = 0; a < n; a++)
    {
        printf("%d\n",TR[a]);
    }
    printf ("----------------------\n");
}

void MergeSort(Sqlist *L)
{
    int *TR = (int*)malloc(L->length*sizeof(int));
    int s = 1;
    while (s<L->length)
    {
        MergePass(L->r,TR,s,L->length);
        s = 2*s;
        MergePass(TR,L->r,s,L->length);
        s = 2*s;
    }
}
int BechmarkHome(Sqlist *L,int low,int high)//完成一次基准归位
{
    int pivotkey;//记录基准,此处设置为子表的第一个作为基准
    pivotkey = L->r[low];
    printf("---------------------\n");
    printf("pivokey:%d\n",pivotkey);
    while (low < high)//开始以基准为参考,把小值放在基准左侧,大值放在右侧
    {
        while(low<high&&L->r[high]>=pivotkey)
            high--;
        Swap(L,low,high);//将比基准值小的值交换到基准的左侧
        printf ("swap %d %d\n",L->r[low],L->r[high]);
        while(low<high && L->r[low]<=pivotkey)
            low++;
        Swap(L,low,high);//将比基准值大的值交换到基准的右侧
        printf ("swap %d %d\n",L->r[low],L->r[high]);
    }
    for(int i=0;i<L->length;i++)
        printf("%d ",L->r[i]);
    printf("\n");
    return low;//返回基准的下标
}
void QSort(Sqlist *L,int low,int high)//递归实现基准的归位,
{
    int pivot;//记录基准的下标
    if(low < high)
    {
        pivot = BechmarkHome(L,low,high);
        QSort(L,low,pivot-1);
        QSort(L,pivot+1,high);
    }
}
void QuickSort(Sqlist *L)
{
    QSort(L,0,L->length-1);//初次开始进行基准归位
}

int Binary_search(Sqlist *L,int key)//二分法查找,基于有序表(一般由小及大)的查找方案.如果没有没有该元素进行插入,如果存在进行删除
{
    int low,high,mid;
    low = 0;
    high = L->length-1;
    while (low<=high)
    {
        mid = (low+high)/2;
        //mid = low + (high-low)*(key-L->r[low])/(L->r[high]-L->r[low]);//改进的二分插值查找法,
        if (key < L->r[mid])
            high = mid-1;
        else if(key>L->r[mid])
            low = mid+1;
        else
            return mid+1;//返回位于第几个位置
    }
    return 0;
}

int main()
{
    Sqlist L;
    L.length = 0;//初始为0
    CreateList(&L,10);
    printf("before the sort:\n");
    PrintList(&L);
    printf("after the sort:\n");
    //std::sort(&(L.r[0]),&(L.r[0])+9);//c++中的sort排序函数,类似快速排序法,默认升序
//    std::make_heap(&(L.r[0]),&(L.r[0])+10);//c++中堆函数,默认大顶堆
//    PrintList(&L);
    //std::sort_heap(&(L.r[0]),&(L.r[0])+10);//c++中的堆排序函数,默认升序
    //BubbleSort(&L);
//    StraightInsertionSort(&L);
    //SimpleSelectSort(&L);
    //StraightInsertionSort(&L);
    ShellSort(&L);
    PrintList(&L);
    //MergeSort(&L);
//    QuickSort(&L);
//    PrintList(&L);
//    int result = Binary_search(&L,42);
//    printf("serach result:%d\n",result);
}

