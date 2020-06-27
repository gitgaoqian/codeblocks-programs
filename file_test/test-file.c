#include <stdio.h> 
int main(void) 
{ 
   FILE *input, *output; 
   char bufr[51200000]; 
   input = fopen("file.txt", "w+");     /*打开文件*/
   if (setvbuf(input, bufr, _IOFBF, 51200000) != 0)  /*失败*/
   {
      printf("failed to set up buffer for input file\n");
   }
      char str[] = "This is runoob.com aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
   int i=0;
   printf("file write start\n");
   for(i=0;i<2000000;i++)
   {
        fwrite(str, sizeof(str) , 1, input );
   }
   printf("file over\n");
   sleep(200); 
   fclose(input); 
   return 0; 
}
