#include<stdio.h>
int main()
{
    int n[3][3]={1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i, j, temp;
    printf("原始矩陣：\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%d  ", n[i][j]);  /*輸出原始矩陣*/
        printf("\n");
    }

    //這一段是轉置矩陣///////////////////////////
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
        {
            if (j>i)
            {  /*將主對角線右上方的陣列元素與主對角線左下方的陣列元素進行單方向交換*/
                temp=n[i][j];
                n[i][j]=n[j][i];
                n[j][i]=temp;
            }
        }
    /////////////////////////////////////////////

    printf("轉置矩陣：\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            printf("%d  ", n[i][j]);  /*輸出原始矩陣的轉置矩陣*/
        printf("\n");
    }
    return 0;
}

/*
補充矩陣相乘 利用轉置會更快

Q2 假設已知二陣列 double a[p][q], b[q][r],
   現欲求 double c[p][r] = a[p][q] * b[q][r]，
   已知 500 < p, q, r < 1000 , 請試完成 c。
   ( as soon as possible. )

A:轉置法

    先將 b[q][r] 轉置成為 b'[r][q]
    變成 rst[i][j] += a[i][k] * b[j][k]
    0 < i < p ; 0 < j < r ; 0 < k < q

        for(i=0; i<p; ++i){
                for(j=0; j<r; ++j){
                        sum = 0.0;
                        for(k=0; k<q; ++k)
                                sum += a[i][k] * b[j][k];
                        rst[i][j] = sum;
                }
        }

　 測試出來 ( wall time testing ) 約比傳統快 6～7 倍

https://www.ptt.cc/bbs/C_and_CPP/M.1338039777.A.FBC.html

*/
