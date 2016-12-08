#include <stdio.h>

char Astring[50];
char Bstring[50];
int A[51];
int B[51];
int Q[51];
int A_backup[51];

int length(char string[])
{
  int i;
  for(i=0; i<50; i++)
  {
    if(string[i]=='\0')
    {
      break;
    }
  }
  return i;
}

void getQ(int i)
{
  int b;
  //Q[i] = 0;
  while( A[i-1]*10+A[i] >= B[1] )
  {
    for(b=length(Bstring); b>0; b--)
    {
      A_backup[b] = A[i-1+b];
    }

    for(b=length(Bstring); b>0; b--)
    {
      if(A[i-1+b] < B[b])
      {
        A[i-2+b]--;
        A[i-1+b] += 10;
        A[i-1+b] -= B[b];
      }
      else
      {
        A[i-1+b] -= B[b];
      }
    }

    if(A[i-1]<0)
    {
      for(b=length(Bstring); b>0; b--)
      {
        A[i-1+b] = A_backup[b];
      }
      break;
    }

    Q[i]++;
  }
}

int main()
{
  int i, shift=0;
  //A[0]=0;
  //B[0]=0;

// input
  scanf("%s", Astring);
  scanf("%s", Bstring);

// if A is shorter than B
  if(length(Astring) < length(Bstring))
  {
    printf("%d", 0);
    printf("\n");
    return 0;
  }

// convert char array to int array
  for(i=0; i<length(Astring); i++)
  {
    A[i+1] = Astring[i] - '0';
  }
  for(i=0; i<length(Bstring); i++)
  {
    B[i+1] = Bstring[i] - '0';
  }

// get Q[]
  for(i=0; i<=length(Astring)-length(Bstring); i++)
  {
    getQ(i+1);
  }

// output
  if(Q[1]==0)
  {
    shift = 1;
  }
  for(i=shift; i<=length(Astring)-length(Bstring); i++)
  {
    printf("%d",Q[i+1]);
  }
  printf("\n");
  return 0;
}
