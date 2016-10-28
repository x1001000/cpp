#include <stdio.h>

int main()
{
    int a, i;
    int f(int n);
    scanf("%d",&a);
    for(i=0; i<a; i++)
        printf("%d ",f(i));
    printf("\n");
    return 0;
}

int f(int n)
{
  if(n>1)
    return f(n-1) + f(n-2);
  else
    return n;
}
