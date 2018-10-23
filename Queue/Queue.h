//队列接口
#define QUEUE_TYPE int //定义队列存储的数据类型

void Insert(QUEUE_TYPE value);//向队列插入元素
void Delete();//从队列删除元素
QUEUE_TYPE First(void);//返回队首元素的值，但是不对队列进行修改
void PrintQueue(void);//打印队列元素
//一个用来判断队列是否空，一个判断队列是否满
bool Is_empty(void);
bool Is_full(void);
//动态数组实现方式此时队列的大小更加灵活：较于静态数组方式，需要另添加队列的创建和销毁函数
void CreateQueue(unsigned int size);//创建队列，用户传递一个参数，用于指定数组的长度
void DestroyQueue();//销毁

//链式队列实现方式，完全不同于数组实现方式，它不在需要循环数组，所以所有的函数必须全部重新声明
void LInsert(QUEUE_TYPE value);
void LDelete(void);
void LPrintQueue(void);
bool LIs_empty(void);
void LDestoryQueue(void);
void LInitial();
QUEUE_TYPE LQueueFont();


