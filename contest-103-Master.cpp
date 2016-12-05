//AC code
#include <bits/stdc++.h>    //標準IO懶人包 裡面就是一堆#include
using namespace std;        //要用include進來的C++的函數就要加這行
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 10;
int dp[maxn][maxn];
int main()
{
    int n , m , ans = -inf;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int a;
            scanf("%d",&a) , dp[i][j] = max(0 , max(dp[i-1][j] , dp[i][j-1]))+a , ans = max(ans , dp[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
//AC code with some printfs
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 10;
int dp[maxn][maxn];
int main()
{
    int n , m , ans = -inf;
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            int a;
            scanf("%d",&a) ;
            printf("%i and %i\n",dp[i-1][j],dp[i][j-1]);
             dp[i][j] = max(0 , max(dp[i-1][j] , dp[i][j-1]))+a ;
             printf("get %i\n",dp[i][j]);
             printf("%i\n",ans);
              ans = max(ans , dp[i][j]);
              printf("%i is bigger\n\n",ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}
//Another AC code
#include<iostream>
#include<string.h>
using namespace std;
int  array[3010][3010];
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        int max=-9999999;
        memset(array,0,sizeof(array));
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin>>array[i][j];
                if(array[i-1][j]>array[i][j-1])
                {
                    if(array[i-1][j]>0)
                        array[i][j]=array[i][j]+array[i-1][j];
                }
                else
                {
                    if(array[i][j-1]>0)
                        array[i][j]=array[i][j]+array[i][j-1];
                }
                if(array[i][j]>max)
                    max=array[i][j];
            }
        }
        cout<<max<<endl;
    }
}
*/
