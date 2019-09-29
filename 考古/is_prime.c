
#include <stdio.h>

int is_prime(int n)
{
    int i;

    if(n==1)
        return 0;

    for(i=2;i*i<=n;i++)  //注意這裡條件不用設 sqrt(n) 直接用i*i<=n就好
    {
        if(n%i==0)
            return 0;
    }

    return 1;

}

int main()
{
    int n;
    n=11;

    if(is_prime(n))
        printf("是質數");
    else
        puts("不是質數");

   return(0);
}

