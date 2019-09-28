#include <stdio.h>
#include <stdlib.h>
int m=2,n=2,i,j;

void GG(int **ptr)
{
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
            printf("%d ",*(*(ptr+i)+j));
    puts("");
    }
}

int main(void)
{
    int **ptr;

    ptr = (int **)malloc( m* sizeof(int));
    for (i = 0; i < m; i++)
        *(ptr+i)= (int *)malloc( n * sizeof(int));

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            *(*(ptr+i)+j)=i+j;  //設定二維陣列的值
    }
    GG(ptr);
    puts("");
    system("pause");
    return 0;
}
