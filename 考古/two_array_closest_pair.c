#include <stdio.h>



struct node{
    int data;
    int flag;
};


void main(void)
{
    int i;
    struct node A[10],tmp;

    for(i=0;i<10;i++)
        A[i].data=i;

    for(i=0;i<10;i++)
        printf("%d ",A[i].data);

    tmp=A[9];
    A[9]=A[0];
    A[0]=tmp;

    puts("");
    for(i=0;i<10;i++)
        printf("%d ",A[i].data);
}
