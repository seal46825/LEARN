#include <stdio.h>
#include <stdlib.h>

//迴圈方法
int fib2(int n){
    int a = 11;
    int b = 12;

    if (n==1)
        return a;
    if (n==2)
        return b;

    for(int i = 2; i < n; i++){
        int tmp = b;
        b += a;
        a = tmp;
    }
    return b;
}

int main(void)
{
    int i,n;
    for(n=1;n<12;n++)
        printf("%4d \n",fib2(n));

   return 0;
}
