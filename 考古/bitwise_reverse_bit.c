//https://hackmd.io/@sysprog/ByzoiggIb?type=view

#include <stdio.h>
#include <stdlib.h>

//左右一直翻轉的做法
unsigned int reverse(unsigned int x)
{
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));
    return((x >> 16) | (x << 16));
}

//先設一個unsigned int reverse_x全部bit都是0
//然後去看要翻轉的數字x最右邊的位元開始看是不是1 如果是就放在reverse_x的最左邊
unsigned int re(unsigned int x)
{
    unsigned int reverse_x = 0;                 //全部bits都是0
    for (int i = 0; i < 32; i++) {
        if((x & (1 << i)))                      //檢查哪些bit是1
            reverse_x  |=  1 << ((32 - 1) - i);   //是1的bit 把reverse_x的對應的翻轉位置改成1
    }
    return reverse_x;
}

int main(void)
{
    unsigned int a=805306368;  //805306368翻轉過來是12


    printf("%d\n", reverse(a));
    printf("%d\n", re(a));
}


