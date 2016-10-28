// 1001000.io

#include <stdio.h>

// 宣告之後要用的變數
int M, P, N, i, S[102];           // S整數陣列最多只需要放102個值(含兩岸)

// 宣告一個傳回1或0的函式，提供if當判斷句使用，檢查N+1次(間隔數=木樁數+1)
int impossible()
{
    for(i=0; i<=N; i++)
    {
        if( M < S[i+1]-S[i] )
        {
            return 1;
        }
    }
    return 0;
}

// 宣告主函式
int main()
{
// scan function for input
    scanf("%d",&M);
    scanf("%d",&P);
    scanf("%d",&N);
    for(i=1; i<=N; i++)
    {
        scanf("%d",&S[i]);
    }
// 兩岸的位置也放進數列
    S[0] = 0;
    S[N+1] = P;
// 先判斷是否IMPOSSIBLE
    if( impossible() )
    {
        printf("IMPOSSIBLE");
    }
    else
    {
// 若不為IMPOSSIBLE 則可以過河
        int t = 0;                // t 為拆橋次數
        int m = M;                // 想像一塊長度可伸長的木板長度為 小寫m = S[某處] + M
        for(i=1; i<=N+1; i++)     // 從S[1]檢查到S[N+1]
        {
            if( m >= S[i])
            {
                continue;         // 若木板夠長，直接continue跳到下一個for
            }
            else                  // 若木板不夠長，則會進到else
            {
                t++;              // 拆橋次數+1
                m = S[i-1] + M;   // 木板安裝到S[i-1]處，如同可伸長的木板伸長為 S[i-1] + M
            }
        }
        printf("%d", t);
    }
    return 0;
}
