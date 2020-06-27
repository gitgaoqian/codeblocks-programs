#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//每次一个字符I/O
/*int main(int argc, char* argv[]){
  FILE *fp = fopen(argv[1], "r+");
  int ret;
  while( (ret=fgetc(fp)) != EOF)
  {
	//printf("%c",(char)ret);
	//将读来的字符写入到标准输出缓冲区
	putc(ret,stdout);
	sleep(1);
  }
 //将缓冲区的内容冲洗到终端输出
  fflush(stdout);
  fclose(fp);
//获取标准输入的内容
  int c=getchar();//等同于getc(stdin)
  putc(c,stdout);//等同于putchar(c)
  fflush(stdout);
  return 0;
}*/
//每次一行字符I/O
/*int main(int argc, char* argv[]){
  FILE *fp = fopen(argv[1], "r+");
  char buf[10];
  while(fgets(buf,sizeof(buf),fp) != NULL)
  {
     	fputs(buf,stdout);
 	fflush(stdout);
  }
  fclose(fp);
  return 0;
}*/
//二进制I/O，按照字节对文件进行读写
int main(int argc,char *argv[])
{
    FILE *file = fopen(argv[1], "w+");
    printf("file:%p",file);
    if(file == NULL)
    {
        printf("fopen error");
        return -1;
    }
    //char a[4] = {'1','2','3','4'};
    int a[4] = {4,9,6,7};
    unsigned int  b = 117;
    size_t write_ret = fwrite(&b, sizeof(int), 1, file);
    if(write_ret != 1)
    {
        printf("fwrite error");
        return -1;
    }
   sleep(20);
    //将文件指针定位到文件开始，否则读取不到数据
    fseek(file, 0, SEEK_SET);
    
    int buf[4] = {};
    size_t read_ret = fread(buf, sizeof(int), 1, file);
    if(read_ret != 1)
    {
        printf("fread error");
        return -1;
    }
   
    fclose(file);
    printf("%d\n", buf[0]);
    sleep(10);
    return 0;
}
//格式化输入输出测试
/*int main(int argc ,char *argv[])
{
    FILE *file = fopen(argv[1], "w+");
    if(file == NULL)
    {
        printf("fopen error");
        return -1;
    }
    int a;
    scanf("%d",&a);
    fprintf(file,"number %d\n",a);
  //定位流：文件指针重新回到文件开头
    fseek(file,0,SEEK_SET); 
    char buf[10];
    int b;
    fscanf(file,"%s %d",buf,&b);
   // snprintf(buf,10,"current number:%d\n",a);
    printf("%s %d",buf,b);	

}*/
