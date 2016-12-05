/*
//�ϥλ��j
//���I�G�Y���j���Ʀh�h����t�׺C
//�u�I�G���ɭԫܦn�g�A�Ҧp������ƥu�n�@�� int f(int n){return n==1?1:n*f(n-1);}
#include <cstdio>               // scanf�Mprintf�bC��<C�зǿ�J�X>library��
#include <utility>              // pair<T1,T2>�bC++��<utility>library��
#define x first                 // �H�Kpair��first�g��x
#define y second                // �H�Kpair��second�g��y
using namespace std;            // ��C++��library���n�[�o��(�O�o����)
int N, M, K, d[10000];
pair<int,int> A, B, Q;          //A,B  �_�I�A���I
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
    Q = P;                    // �W
    Q.y = ((Q.y-d[k]%N)+N)%N;
    if(onTheWayHome(Q, k+1))
        return true;
    Q = P;                    // �U
    Q.y = (Q.y+d[k]%N)%N;
    if(onTheWayHome(Q, k+1))
        return true;
    Q = P;                    // ��
    Q.x = ((Q.x-d[k]%M)+M)%M;
    if(onTheWayHome(Q, k+1))
        return true;
    Q = P;                    // �k
    Q.x = (Q.x+d[k]%M)%M;
    if(onTheWayHome(Q, k+1))
        return true;
    return false;
}
*/
//Best practice
//�_�I���O���A�W�U���k�Y�Z�����O���A�_�I�����O���A���O�����I��_�I�A�@���ܰʨ�̫�ݲ��I���S���O���C
//�u�I�G���O������m�����C(�Q�Q������H)
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
