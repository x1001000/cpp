// 1001000
#include <stdio.h>

int N, M, A[200], B[200], P[200], T[200], Nb, Ne, HH[2], MM[2];
int ways[50][50], way, station; // ways[way][0]存行駛時間 ways[way][1~50]存路由
int t[100];                     // stack for 行駛時間

void get_ways(int, int);
int most_possible(), mp;
int arrive_time(int);

int main()
{
  int i, j;
  while(1)
  {
    way = station = 0;
    scanf("%i %i", &N, &M);
    if(N==0&&M==0)
      break;
    for(i=0; i<M; i++)
      scanf("%i %i %i %i", &A[i], &B[i], &P[i], &T[i]);
    scanf("%i %i", &Nb, &Ne);
    scanf("%i:%i", &HH[0], &MM[0]);
    scanf("%i:%i", &HH[1], &MM[1]);
    MM[0] += HH[0]*60;
    MM[1] += HH[1]*60;
    get_ways(Nb, Ne);
    i = way;
    while(i--)
    {
      mp = most_possible();
      station = 1;
      //printf("%i\n", mp);
      if(arrive_time(MM[0]) <= MM[1])
      {
        printf("%i\n", MM[1]-MM[0]-ways[mp][0]);
        break;
      }
      ways[mp][0] = 0;
    }
    if(i==0)
      printf("No way");
  /* print input
  for(i=0; i<7; i++)
    printf("%i %i %i %i\n", A[i], B[i], P[i], T[i]);
  printf("%i %i %i %i\n", Nb, Ne, MM[0], MM[1]); // */
  /* print ways[][]
  for(i=0; i<way; i++){
    for(j=0; j<50; j++)
      printf("%i_", ways[i][j]);
    printf("\n");} // */
  }
  return 0;
}

void get_ways(int here, int there)
{
  int i, j;
  if(here == there)
  {
    ways[way][0] = 0;
    for(i=0; i<station; i++)
      ways[way][0] += t[i];             //sum up t stack in this way
    station--;
    way++;
    return;
  }
  for(i=0; i<M; i++)
  {
    if(A[i] == here)
    {
      //printf("%i_%i\n", A[i], B[i]);  // print from_to
      t[station++] = T[i];              // push T[i] into t stack
      for(j=way; j<50; j++)
      {
        /* 改存i
        ways[j][station] = A[i];
        ways[j][station+1] = B[i]; // */
        ways[j][station] = i;
      }
      get_ways(B[i], there);
    }
  }
  station--;
}

int most_possible()
{
  int i, big, most_possible;
  for(i=0; i<way; i++)
    if(ways[i][0]>big)
    {
      big = ways[i][0];
      most_possible = i;
    }
  return most_possible;
}

int arrive_time(int now)
{
  int i = ways[mp][station++];
  int then = (now + P[i] - 1) / P[i] * P[i] + T[i];   // round-up
  if(B[i] == Ne)
    return then;
  return arrive_time(then);
}
