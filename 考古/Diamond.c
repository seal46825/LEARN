#include <stdio.h>
#include <stdlib.h>
int i,j;
int H,W=5;
//star1~star4的撰寫都要用高度H去想比較好
//因此要把寬度W轉換成高度H    H=(W+1)/2

//star1、star2的高度H=寬度W
//star3、star4的上半菱形高度為(W+1)/2
//star4就是把star3的上半菱形補上下半部 記得i要從H-2開始

void star1(void){
    puts("Star1:");
    H=W;
    for(i=0;i<H;i++){
        for(j=0;j<i+1;j++)
            printf("*");
        puts("");
    }
}

void star2(void){   //因為H=5有5行 每一行有五個元素 星星加空白要等於5
    puts("Star2:");
    H=W;
    for(i=0;i<H;i++){
        for(j=0;j<H-i-1;j++)
            printf(" ");
        for(j=0;j<i+1;j++)
            printf("*");
        puts("");
    }
}

/*最底層是1 每往上一層就+2 加到n為止 以n=5為例:
55555
 333
  1
star22為code */
void star22(n){
    puts("Star22:");
    H=(n+1)/2;
    for(i=0;i<H;i++){
        for(j=0;j<i;j++)
            printf(" ");
        for(j=0;j<n-i*2;j++)
            printf("%d",n-i*2);
        puts("");
    }
    puts("");
}

void star23(n){
    puts("Star23:");
    H=(n+1)/2;
    for(i=0;i<H;i++){
        for(j=0;j<H-i-1;j++)
            printf(" ");
        for(j=0;j<i*2+1;j++)
            printf("%d",n-i*2);
        puts("");
    }
    puts("");
}

void star3(void){
    puts("Star3:");
    int H=(W+1)/2;
    for(i=0;i<H;i++){
        for(j=0;j<H-i-1;j++)
            printf(" ");
        for(j=0;j<i*2+1;j++)
            printf("*");
        puts("");
    }
    puts("");

}

void star4(void){
    puts("Star4:");
    int H=(W+1)/2;

    for(i=0;i<H;i++){
        for(j=0;j<H-i-1;j++)
            printf(" ");
        for(j=0;j<i*2+1;j++)
            printf("*");
        puts("");
    }

    //原本印到H-1 因為下半部要少一階 因此從H-2開始
    for(i=H-2;i>=0;i--){
        for(j=0;j<H-i-1;j++)
            printf(" ");
        for(j=0;j<i*2+1;j++)
            printf("*");
        puts("");
    }

}

int main()
{
   int i;
   star1();
   star2();
   star22(9);
   star23(9);
   star3();
   star4();


   return(0);
}
