#include <stdio.h>
#include <string.h>
//strstr and memcpy
int main(void)
{
    char src_buffer[30] = "slfGPMA89484949020GQ4";
   char *src = src_buffer, *find1 = "GPMA", *find2="GQ", *return_ptr1,*return_ptr2;
   char dest_buffer[30];

   return_ptr1 = strstr(src, find1);
   return_ptr2 = strstr(src,find2);
   printf("lenth:%d\n",return_ptr2-return_ptr1);
   memcpy(dest_buffer,return_ptr1,(return_ptr2-return_ptr1));
   printf("The substring is: %s\n", dest_buffer);
   return 0;
}
