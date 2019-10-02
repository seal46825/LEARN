//找出小於n有幾個質數
int countPrimes(int n){
    
    int *prime,i,cnt=0,j;
    prime=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        prime[i]=1;  //先設全部都是1
    
    for(i=2;i<n;i++)
    {
        if(prime[i]==0)  //如果有些數確定不是質數 直接跳過
            continue;
        cnt++;
        for(j=2;i*j<n;j++)  //把前幾個數字的倍數全部找出來 把它標成非質數
            prime[i*j]=0;
        
    }

    
    return cnt;
}

