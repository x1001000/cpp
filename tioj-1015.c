// 用數學公式解決跑迴圈超時的問題

#include<stdio.h>
unsigned long long int M,N,B,S,K[10001];
int main()
{
    int i,j=0;
    while(1)
    {
        scanf("%d %d",&M,&N);
        if(M==0&&N==0)
            break;

        if(M>N)
        {
            B=M;
            S=N;
        }
        else
        {
            B=N;
            S=M;
        }

        //     (BS)(S+1) - (B+S)(1+...+S) + (1^2+..+S^2)
        K[j] = B*S*(S+1) - (B+S)*S*(S+1)/2 + S*(S+1)*(2*S+1)/6;

/*
        for(i=0; i<shorter; i++)
        {
            K[j]+=(M-i)*(N-i);
        }
*/
        j++;
    }

    for(i=0; i<j; i++)
    {
        printf("%llu",K[i]);
        printf("\n");
    }
    return 0;
}
