#實作STRCPY

#include <stdio.h>

void STRCPY (char *str1,char *str2)
{
    while(*str2!='\0')
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    str1='\0';
}

int main(void)
{
    char *str2="TEST";
    char str1[10];
    STRCPY(str1,str2);
    puts(str1);
}
