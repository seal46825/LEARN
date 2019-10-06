#include <stdio.h>

//判斷是否為2的次方

int identify(int a){
    int cnt=0;

    while(a){
        if(a&1==1)
            cnt++;
        a=a>>1;
        printf("a=%d cnt=%d\n",a,cnt);

        if(cnt>1)
            return 0;
    }

    if(cnt==1)
        return 1;
    else
        return 0;

}



int main()
{
    int a;

    while(1){

            printf("請輸入一個數字:");
        scanf("%d",&a);

        if(identify(a))
            printf("%d為2的次方",a);
        else
            printf("%d不是2的次方",a);

        puts("\n");

    }

}


