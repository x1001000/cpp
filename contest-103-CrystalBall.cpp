/*
//使用遞迴
//缺點：若遞迴次數多則執行速度慢
//優點：有時候很好寫，例如階乘函數只要一行 int f(int n){return n==1?1:n*f(n-1);}
#include <cstdio>               // scanf和printf在C的<C標準輸入出>library內
#include <utility>              // pair<T1,T2>在C++的<utility>library內
#define x first                 // 以便pair的first寫成x
#define y second                // 以便pair的second寫成y
using namespace std;            // 用C++的library都要加這行(記得分號)
int N, M, K, d[10000];
pair<int,int> A, B, Q;          //A,B  起點，終點
bool onTheWayHome(pair<int,int>, int);

int main()
{
    scanf("%i%i%i%i%i%i%i", &N, &M, &A.y, &A.x, &B.y, &B.x, &K);
    for(int k=0; k<K; k++)
        scanf("%i", &d[k]);
    printf("%s", onTheWayHome(A,0)?"YES":"NO");
    return 0;
}

bool onTheWayHome(pair<int,int> P, int k)
{
    if(k==K)
        if(P==B)
        {
            printf("[%i,%i]",P.x,P.y);
            return true;
        }
        else
        {
            printf("(%i,%i)",P.x,P.y);
            return false;
        }
       // return P==B ? true : false;
    Q = P;                    // 上
    Q.y = ((Q.y-d[k]%N)+N)%N;
    if(onTheWayHome(Q, k+1))
        return true;
    Q = P;                    // 下
    Q.y = (Q.y+d[k]%N)%N;
    if(onTheWayHome(Q, k+1))
        return true;
    Q = P;                    // 左
    Q.x = ((Q.x-d[k]%M)+M)%M;
    if(onTheWayHome(Q, k+1))
        return true;
    Q = P;                    // 右
    Q.x = (Q.x+d[k]%M)%M;
    if(onTheWayHome(Q, k+1))
        return true;
    return false;
}
*/
//Best practice
//起點做記號，上下左右某距離做記號，起點取消記號，有記號的點當起點，一直變動到最後看終點有沒有記號。
//優點：有記號的位置有限。(想想為什麼？)
#include<cstdio>
#include<cstdlib>
using namespace std;
int dx[]= {1,0,-1,0}, dy[]= {0,1,0,-1};
bool cb[2][105][105];
int main()
{
    int N, M, X1, Y1, X2, Y2, K, d, a, b;
    scanf("%d %d %d %d %d %d %d",&N, &M, &X1, &Y1, &X2, &Y2, &K);
    cb[0][X1][Y1]=1;
    for(int k=0; k<K; k++)
    {
        scanf("%d",&d);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {
                if(cb[k&1][i][j])
                {
                    for(int m=0; m<4; m++)
                    {
                        a=(i+(dx[m]*d)%N+N)%N;
                        b=(j+(dy[m]*d)%M+M)%M;
                        cb[(k+1)&1][a][b]=1;
                    }
                    cb[k&1][i][j]=0;
                }
            }
    }
    puts(cb[K&1][X2][Y2] ? "YES" : "NO");
    //system("pause");
    return 0;
}
