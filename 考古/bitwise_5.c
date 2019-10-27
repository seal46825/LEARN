//不用if、?等敘述 判斷兩個數哪個大
#include <stdio.h>
#include <stdlib.h>

//原理 a-b 如果結果是正 sign_bit會是0  如果是負則為-1

int max(int a, int b)
{
    int diff = a - b;
    int sign_bit= (unsigned)diff  >> (sizeof(int) * 8 - 1); 
    //為何diff要轉unsinged? 不然如果是負的 因為sign_bit是-1 最後的結果會是-1不是1
    printf("%d\n",sign_bit);
    int array[] = {a, b};
    return array[sign_bit];
}

int main(void)
{
    printf("%d\n",max(10,40));
   return 0;
}

