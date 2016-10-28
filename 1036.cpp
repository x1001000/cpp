// 1001000
#include <stdio.h>
#include <stdbool.h>
bool isPrime[10000001];
int main()
{
  isPrime[2] = true;
  for(int i=3; i<=10000000; i+=2)
    isPrime[i] = true;
  for(int i=3; i<=10000000; i+=2)
    if(isPrime[i])
      for(long long j = (long long)i*i; j<=10000000; j+=i)
        isPrime[j] = false;
  int m;
  scanf("%d", &m);
  while(m--)
  {
    int n;
    scanf("%d", &n);
    if(n==0)
        break;
    int i=n+1, sum=0;
    while(i--)
      sum += isPrime[i];
    printf("%d\n", sum);
  }
  return 0;
}
