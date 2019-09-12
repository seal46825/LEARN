
#include <stdio.h>

int is_prime(int n)
{
    int i;

    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return 0;
    }

    return 1;

}

int main()
{
    int n;
    n=2;

    if(is_prime(n))
        printf("是質數");
    else
        puts("不是質數");

   return(0);
}

