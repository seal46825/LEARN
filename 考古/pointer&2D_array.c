
#include <stdio.h>

void pass(int(*array)[2])
{
    int i,j;
    for(i=0;i<2;i++)
    {
        printf("%d row:",i+1);
        for(j=0;j<2;j++)
        {
            printf("%d ",array[i][j]);
        }
        puts("");
    }
    return;
}
// array 是個指標，指向 int [2]


int main(void)
{
    int a[2][2]={{1,2},{3,4}};
    pass(a);
}
