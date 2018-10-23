#include<stdio.h>
#include<string.h>
#include<iostream>
int main()
{
    char * src = "He";
    char dest[40] = "elf";
    printf("%d\n",src);
    printf("%d\n",dest);
    //strcpy(dest,src);
    memcpy(dest,src,4);
    printf("%s",dest);
}

