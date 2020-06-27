#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//模拟touch命令
/*int main(int argc, char* argv[]){
  int fd = open(argv[1], O_RDONLY|O_CREAT|O_EXCL, 0666);
  close(fd);
  return 0;
}*/
//模拟cat命令
/*int main(int argc, char* argv[]){
  int fd = open(argv[1], O_RDONLY);
  printf("open fd:%d\n",fd);
  char buf[64] = {0};
  int ret = 0;
  
  while((ret = read(fd, buf, sizeof(buf))) > 0){
    printf("read ret:%d\n",ret);
   write(STDOUT_FILENO, buf, ret);
  }
  close(fd);
  return 0;
}*/
//测试lseek函数
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  int fd = open(argv[1], O_RDWR|O_CREAT, 0666);
  int i = 0;
  printf("write start\n");
  for(i=0;i<10240000;i++)
  {
	write(fd, "helloworld\n", 11);
  }
  printf("write finished\n");
  sleep(10);
  //这里必须使用lseek，来调整文件指针的位置，设置文件指针设置到文件的开始位置。
  lseek(fd, 2, SEEK_SET);
  char buf[20] = {0};
  int ret = read(fd, buf, sizeof buf);
  write(STDOUT_FILENO, buf, ret);
  printf("close the fd\n");
  close(fd);
  return 0;
}
