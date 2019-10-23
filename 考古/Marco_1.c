#include <stdio.h>
#include <stdlib.h>
#define ADD_TWO(x,y) x += 2; y +=2

int flag = 0;
int j = 5, k = 7;

int main(void){

    if(flag)
        ADD_TWO(j,k);
    printf("j=%d, k=%d\n",j,k);
    return 1;
}

//這題的觀念在於 marco的x+=2會包在10th的if裡面 但是y+=2是在if外面 
//https://blog.csdn.net/mingzhentanwo/article/details/44993771
