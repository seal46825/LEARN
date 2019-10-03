/* hw8_18.c */
#include <stdio.h>
#include <stdlib.h>

//遞迴方法
int fib(int n)
{
    int ans;
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return(fib(n-1)+fib(n-2));
}
//迴圈方法
int fib2(int n){
    int a = 1;
    int b = 1;

    for(int i = 2; i < n; i++){
        int tmp = b;
        b += a;
        a = tmp;
    }
    return b;
}

int main(void)
{
    int i,a;
    a=5;
   printf("%d %d",fib(a),fib2(a));
   return 0;
}

