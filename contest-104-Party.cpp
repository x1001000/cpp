#include <iostream>
using namespace std;

int m, n, dp[1001][1001];
bool A[1001], B[1001];
int main()
{
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>A[i];
    for(int i=1; i<=n; i++)
        cin>>B[i];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(A[i]!=B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    cout<<dp[m][n];
    return 0;
}
