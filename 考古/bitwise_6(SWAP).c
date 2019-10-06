//不用暫存做SWAP

int main()
{
    int a=1,b=2;

    printf("a=%d b=%d\n",a,b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a=%d b=%d",a,b);
}

/* 證明:
第3行b=a
證明:
b=a^b^b
由於b^b=0
因此b=a^0=a

第4行a=b
證明:
a=a^b^a
=a^a^b
=0^b=b
*/
