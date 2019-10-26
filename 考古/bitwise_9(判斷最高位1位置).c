#include <stdio.h>
#include <stdlib.h>

int get(unsigned x){
    int n = 31;
    if(x == 0) return -1;
    if((x>>16) == 0) { n = n - 16; x = x << 16;}
    if((x>>24) == 0) { n = n -  8; x = x <<  8;}
    if((x>>28) == 0) { n = n -  4; x = x <<  4;}
    if((x>>30) == 0) { n = n -  2; x = x <<  2;}
    if((x>>31) == 0) { n = n -  1;}
    return n;
}

int get1(unsigned x){
    int cnt=-1;
    while(x){
        x=x>>1;
        cnt++;
    }
    return cnt;
}

int main()
{
   unsigned int a=1;
   a=a<<9;

   printf("%d\n",get(a));
   printf("%d\n",get1(a));

   return(0);
}
