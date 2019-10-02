//計算轉成二進位後 有幾個1
#include <stdio.h>
#include <stdlib.h>

int NumberOf1_Solution1(int i)
{
      int count = 0,j;
      while(i)
      {
            if(i & 1)
                  count ++;

            i = i >> 1;
      }

      return count;
}

int main (void){

    int a=10; //1010
    printf("%d \n",NumberOf1_Solution1(a));

}
