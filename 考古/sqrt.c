int main(void)
{
    int a;
    scanf("%d",&a);
    float temp=1;
    
    while(a-temp*temp>0.0001)
        temp+=0.00001;
        
    printf("%5f",temp);
}
