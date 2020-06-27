include<stdio.h>
#include<unistd.h>
#define BUF_SIZE 524288000
int main ()
{
   FILE *fp;
   char str[] = "This is runoob.com aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
   fp = fopen( "file.txt" , "w+" );
   char buf[BUF_SIZE] = {0};
   setvbuf(fp, buf, _IOFBF, 512); 
   int i=0;
   printf("file write start\n");
   for(i=0;i<2000000;i++)
   {
   	fwrite(str, sizeof(str) , 1, fp );
   }
   printf("file over\n");
   sleep(200);
   fclose(fp);
  
   return(0);
}
