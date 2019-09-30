#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int queue[MAX];
int front=-1,rear=-1;

int is_full(void)
{
    if(rear==MAX-1)
        return 1;
    return 0;
}

void enqueue (int a)
{
    if(is_full())
        puts("已滿\n");
    else
        queue[++rear]=a;
}

void dequeue(void)
{
    if(front==rear)  //如果queue裡已經沒東西
        puts("已空\n");
    else
        printf("元素%d已被取出\n",queue[++front]);

}

int main(void)
{
    int x;

    while(1)
    {
        printf("輸入數字放進QUEUE 輸入-1取出:");
        scanf("%d",&x);

        if(x==-1)
            dequeue();
        else
            enqueue(x);
    }

    return 0;
}


