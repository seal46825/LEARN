#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    scanf("%d",&a);
    float ans;
    float low = 0, high = a, mid;
    
    while(abs(a- mid * mid) > 0.0001) {
        mid = (low + high) / 2;
        
        if (mid * mid > a) {
            high = mid;
        } else if (mid * mid < a) {
            low = mid;
        }
    }
    printf("%5f",mid);
}
