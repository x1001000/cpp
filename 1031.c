// 1001000
#include <stdio.h>
int a[100];
int calc();
int max2n(int);
int main()
{
    int i=0, ai, next=0;
    while(1)
    {
        scanf("%i", &ai);
        a[i++] = ai;
        if(ai==0)
        {
            printf("%i\n", calc());
            scanf("%i", &next);
            if(next==0)
                break;
            else
            {
                for(i=0; i<100; i++)          // reset a[100]
                    a[i]=0;
                i=0;
                a[i++]=next;                  // a[0] = next
            }
        }
    }
    return 0;
}
int calc()
{
    int i, sum=0;
    for(i=0; i<100; i++)
    {
        if(a[i]==0)
            break;
        sum += max2n(a[i]);
    }
    return sum;
}
int max2n(int N)
{
    int n=0, i, max=1;
    while(N!=1)
    {
        N /= 2;
        n++;
    }
    for(i=0; i<n; i++)
        max *= 2;
    return max;
}
