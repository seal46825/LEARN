#include <stdio.h>
#include <stdlib.h>
#define NUM 20   //數字範圍0 ~ NUM-1
#define SIZE 20 //要印幾次數字

int main(void)
{
    int i,a,cnt=0;
    int num=NUM;
    int *arr;
    arr=(int*)malloc(num*sizeof(int));

    for(i=0;i<num;i++)
        arr[i]=i;

    while(cnt<SIZE){

        a=rand()%num;  //隨機取數
        printf("%d ",arr[a]);
        
        arr[a]=arr[num-1];  //把印過的元素丟掉 最後一個元素補過來
        num--;
        
        cnt++;
    }
}



/* 舊版 最後會一直撞到 不好
#include <stdio.h>
#include <stdlib.h>
#define NUM 501   //數字範圍0 ~ NUM-1
#define SIZE 20 //要幾幾次數字

int main(void)
{
    int i,a,cnt=0;
    int arr[NUM];  //創一個矩陣來記錄哪些被印過

    for(i=0;i<NUM;i++) //矩陣初始化為0
        arr[i]=0;

    while(cnt<SIZE){

        a=rand()%NUM;  //隨機取數
        if(arr[a]==1)  //如果該數之前有取過
            continue;  //重來

        arr[a]=1;      //取過的數把它標記成1 代表已取過
        printf("%d ",a);
        cnt++;
    }
}
*/
