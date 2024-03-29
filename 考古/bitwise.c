#include <stdio.h>


/* Function to check if n is a multiple of 3*/


int multiple_of_three(int num) {
    //puts("GO!");
    if (num < 0)
        num = -num; 
    //為何要正? 不然最後剩sign_bit是-1會影響 (為何-1? 因為就算移到最右邊他還是sign_bit 會等於-1)

    if (num == 0)
        return 1; // true
    if (num == 1 || num == 2)
        return 0; // false

    int even = 0, odd = 0;

    while (num != 0) {
        even += (num & 0x1);  //將偶數的位元將加總起來 (2進制只有1)
        num >>= 1;
        odd += (num & 0x1);   //將雙數的位元將加總起來 (2進制只有1)
        num >>= 1;
    }
    //printf("even=%d odd=%d even-odd=%d\n",even,odd,even-odd);
    return multiple_of_three(even - odd);
    //丟一個數字一直判斷下去 如果是三的倍數最後一定會是3 如果是3 even=odd=1
    //1-1=0  0丟進遞迴會return 1 因此如果是3的倍數最後會return 1
}


/* Program to test function isMultipleOf3 */
int main()
{
    int num = 369369396;

    if (multiple_of_three(num))
        printf("%d is multiple of 3", num);
    else
        printf("%d is not a multiple of 3", num);
    return 0;
}
