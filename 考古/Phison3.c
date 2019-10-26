#include <stdio.h>
#include <stdlib.h>

/*題目會給一個int a[20]已排序的陣列，
請寫一個function(a, size)能印出0~500的數字，且不包含a陣列內的元素，
請用最少的時間和空間複雜度完成。*/

void Q1(int* a, int size){
    printf(" \nQuestion1 : \n");

    int i;
    for(i = 0; i<= 500; i++){
        if(i == *a){
            a++;  //指標下移
        }else{
            printf("%d , ", i);
        }
    }
}
/*題目會給一個int a[20]已排序的陣列，
請寫一個function(a, size, b)能依照參數b(b = 0~4)別印出該區間的數字，
且不包含a陣列內的元素，
例如：
　b = 0, 印出0~99
　b = 1, 印出100~199
　...
請用最少的時間和空間複雜度完成。 */
void Q2(int* a, int size, int b){
    printf(" \nQuestion2 : \n");

    int idx=0,i;

    //依照b設定符合a[]的範圍
    while(a[idx] < b*100 && idx<size){
        idx++;
    }


    for(i = b*100; i < (b+1)*100; i++){
        if(i == a[idx]){
            //index下移
            idx++;
        }else{
            printf("%d , ",i);
        }
    }
}

int main(void){

    int i;
    unsigned int a[20]={1,5,9,11,18,21,23,53,200,230,330,331,332,333,400,401,405,430,450,480};

    for(i=0;i<20;i++)
        printf("%d ",a[i]);

    puts("");
    Q1(a,20);

    puts("");
    Q2(a,20,3);

    return 0;
}
