#include <stdio.h>

//給定一個正整數數列進行排列，使其奇數在前，偶數在後。奇數部份由小到大排列，偶數部份由大到小排列

void sort(int *arr,int n){

    int *arr1,i,j,k;
    arr1=(int*)malloc(n*sizeof(int));

    for(i=0;i<n;i++)
        arr1[i]=arr[i];

    for(i=0,j=0,k=n-1;i<n;i++){

        if(arr1[i]%2!=0)
            arr[j++]=arr1[i];
        else
            arr[k--]=arr1[i];

    }
}

void bubble(int *arr,int n){
    int i,j,tmp;

    for(i=1;i<n;i++){
        for(j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }

}

int main()
{
    int i;
    int arr[7]={191,24,33,81,246,17,68};
    bubble(arr,7);
    for(i=0;i<7;i++){
        printf("%d ",arr[i]);
    }
    sort(arr,7);
    puts("");
    for(i=0;i<7;i++){
        printf("%d ",arr[i]);
    }

}


