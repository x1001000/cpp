// 1001000
#include <stdio.h>
#include <math.h>
int gcd(int,int);
int isCoprime(int,int);
int main()
{
  while(1)
  {
    int a[50], N, i, j, sum=0;    // reset to 0
    long double CN2;                     // use long type
    scanf("%i", &N);
    if(N==0)
      break;
    CN2 = N*(N-1)/2;
    for(i=0; i<N; i++)
    {
      scanf("%i", &a[i]);
      for(j=0; j<i; j++)
        sum += isCoprime(a[i],a[j]);
    }
    if(sum==0)
      printf("No estimate for this data set.\n");
    else
      printf("%.6Lf\n", sqrtl(6*CN2/sum));
  }
  return 0;
}
int gcd(int a,int b)
{
  if(a==0)
    return b;
  return gcd(b%a, a);
}
int isCoprime(int a,int b)
{
  if(gcd(a,b)==1)
    return 1;
  return 0;
}
