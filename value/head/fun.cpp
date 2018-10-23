static int a = 10; //设置变量为静态链接，说明其不能够被别的文件调用？
extern float b=10.0;
int fun (int i,int j)
{
    int c;
    c = i+j;
    return c;
}
