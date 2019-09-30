/*=========================================================

       Page 7-27 快速排序法

          quick_sort()          快速排序法函式
          partition()           分割陣列函式
          a[ARR_NUM]            欲排序之資料
          ARR_NUM               欲排序之資料數目(陣列大小)

  =========================================================
*/

#include <stdio.h>

#define ARR_NUM 9
void quick_sort(int [],int,int);
int partition(int [],int,int);

void main(void)
{
   int a[ARR_NUM]={371,414,19,-81,141,25,56,61,49},i;

   printf("排序前 ( before sorting ):\n");
   for(i=0;i < ARR_NUM;i++)
        printf(" %d",a[i]);

   quick_sort(a,0,ARR_NUM-1);

   printf("\n排序後 ( after sorting ):\n");
   for(i=0;i < ARR_NUM;i++)
        printf(" %d",a[i]);
   printf("\n");
}

/*快速排序法*/
void quick_sort(int a[],int l,int r)  //l是矩陣的左限(ex:[0]) r是右限
{
   int partition_point;
   if(l <r) //這裡原本有"="  我刪掉了
   {
        partition_point=partition(a,l,r);       //進行分割 傳回分割點

        quick_sort(a,l,partition_point-1);      //繼續處理分割後的左半部

        quick_sort(a,partition_point+1,r);      //繼續處理分割後的右半部
   }
}

/*對 a[l]..a[r] 進行分割,傳回分割點*/
int partition(int a[],int l,int r)
{
   int i,j,temp;

   i=l+1;    //以左限a[l]當基準點 從l+1也就是i開始做比較處理
   j=r;
   while(1)
   {
        while(a[i]<a[l] && i<r) //左邊i遞增 直到a[i]>=基準值 &&<r是怕衝過頭
                i++;
        while(a[j] > a[l])       //這邊不用&& j>=l 因為j減到最後會遇到自己l
                j--;
        //下面(i>=j)沒加等於的話 會讓迴圈永遠跳不出來 應該是因為剩兩個元素的狀態 例如 21 18 這時l=0 但i=j=1而且不會再動了 因此無法達成i>j條件 迴圈跳不出去
        if(i >= j)               //經過上面兩個處理後 若i>=j 脫離迴圈
                break;
        temp=a[i];               //如果沒交錯 則交換a[i]、a[j]
        a[i]=a[j];
        a[j]=temp;
   }
   //如果交錯 a[j]跟基準值交換  不能跟a[i]換
   //因為i會停下來就是因為a[i]比基準值大 a[i]換到最左邊的話會使得基準值左邊有一個比他大的值
   temp=a[l];
   a[l]=a[j];
   a[j]=temp;

   return(j);                    //將分割點的index傳回
}
