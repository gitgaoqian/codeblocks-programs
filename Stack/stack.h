#define STACK_TYPE int //定义堆栈存储的数据类型

void Push(STACK_TYPE value);//push:把一个新值压入到堆栈中，他的参数是需要被压人的值
void Pop(void);//pop:把栈顶的值弹出堆栈*/
STACK_TYPE Top(void);//top:返回堆栈顶部元素的值，但是不对堆栈进行修改
void PrintStack(void);//打印栈，自顶而下
//增加两个函数，一个用来判断堆栈是否空，一个判断堆栈是否满
bool Is_empty(void);
bool Is_full(void);


//动态数组实现方式：较于静态数组方式，需要另添加栈的创建和销毁函数
void CreateStack(unsigned int size);//创建栈，用户传递一个参数，用于指定数组的长度
void DestroyStack();//销毁栈，，因为这些占用的内存是在运行时堆上，不会在程序退出后释放。而存放在栈上面的会在程序退出后自动释放

//链式堆栈实现方式，完全不同于数组实现方式，所以所有的函数必须全部重新声明
void LPush(STACK_TYPE value);
void LPop(void);
STACK_TYPE LTop(void);
void LPrintStack(void);
bool LIs_empty(void);
void LDestoryStack(void);
