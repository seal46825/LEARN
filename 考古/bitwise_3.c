//不用乘法實現乘法
#include <stdio.h>
#include <string.h>

int QQ(int a, int b)
{

    if (b < 0)
        b = -b;

    if (a < 0)
        a = -a;

    int ret = 0;

    while (b) //如果b不是0
    {
        if (b & 1)  //當第一個位元為1
            ret = ret + a; //把a加進去
        
        //很難解釋 就是長乘法的概念 只是為二進制 a*(b第一個位元)+a*(2^1)*(b的第二個位元)+a*(2^2)*(b的第三個位元)+...
        //參考https://blog.csdn.net/chen134225/article/details/81569009 的表比較好懂
        a <<= 1;  
        b >>= 1;
    }

    return ret;
}

int main()
{
    printf("%d \n",QQ(3,-5));

   return(0);
}

