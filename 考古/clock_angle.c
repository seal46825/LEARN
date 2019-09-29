/*
H角度:(h*60+m)*0.5
M角度:m*6
*/

#include <stdio.h>


int main()
{
    int h,m;
    float H,M,ans;

    puts("請輸入 時/分");
    scanf("%d %d",&h,&m);

    H=(h*60.0+m)*0.5;  // 12小時*60分鐘 共720分鐘 代表一分鐘是360/720=0.5度  因此時針的度數是(h*60.0+m)*0.5
    M=m*6.0;           // 轉一圈60分鐘  代表一分鐘為360/60=6度
    printf("h=%d m=%d \nH=%.2f M=%.2f\n",h,m,H,M);

    ans=H-M;
    if(ans<0)
        ans*=-1;
    if(ans>180)
        ans=360-ans;

    printf("ans=%.2f\n",ans);


   return(0);
}

