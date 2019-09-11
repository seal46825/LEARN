
#include <stdio.h>

typedef unsigned long DWORD;
DWORD fun(DWORD num)
{
DWORD h, l;
h = num << 16;
l = num >> 16;
return h | l;
}

int main()
{
   printf("%p",fun(0x12345678));

   return(0);
}

