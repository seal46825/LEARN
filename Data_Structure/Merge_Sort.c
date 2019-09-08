
#include<stdio.h>
#include<stdlib.h>

#define ARR_NUM 5

void merge_sort(int a[],int l,int r)
{
    int i,j,k,m;
    int b[ARR_NUM];  //宣告b陣列來將a複製到b以便排序
    if(l<r)
    {
        m=(l+r)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);

        for(i=l;i<=r;i++)   //先將a複製到b
            b[i]=a[i];

        for(i=l,j=l,k=m+1; i<=r;i++)   //由m當分割點把b分成兩段 然後兩段比大小合併到a
        {
            if(j>m)          //如果b左邊那段超過右限m 代表到底了 把右邊那段丟進a
                a[i]=b[k++];
            else if(k>r)     //如果b右邊那段超過右限r 代表到底了 把左邊那段丟進a
                a[i]=b[j++];
            else             //b的兩段都沒有超過右限 從第一個元素開始比大小 小的丟進a
                a[i]= b[j]<b[k]? b[j++]:b[k++];
        }
    }
}

int main(void)
{
    int i,a[]={5,1,2,7,3};
    merge_sort(a,0,4);

    puts("排序後:");
    for(i=0;i<ARR_NUM;i++)
        printf("%d ",a[i]);

    return 0;
}


