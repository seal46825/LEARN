//不用if、?等敘述 判斷兩個數哪個大
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    int diff = a - b;
    int sign_bit= (unsigned)diff  >> (sizeof(int) * 8 - 1);
    int array[] = {a, b};
    return array[sign_bit];
}

int main(void)
{
    printf("%d\n",max(10,40));
   return 0;
}

