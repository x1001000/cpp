// 1001000
#include <stdio.h>
int main()
{
    while(1)
    {
        int n, i, big=0;
        long sum=0;
        scanf("%d",&n);
        if(n==0)
            break;
        int m[n];
        i=n;
        while(i--)
        {
            scanf("%d",&m[i]);
            if(m[i] > big)
                big = m[i];
        }
        i=n;
        while(i--)
            sum += m[i];
        printf("%ld\n", sum + big + 1);
    }
    return 0;
}
