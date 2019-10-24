
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
