// 1001000.io
#include <stdio.h>
#include <string.h>         // Include this header for string comparison
int main(){
// 變數宣告
  char input[10];
  int N;                    // Value is 0 by default
  char day[7][10] = { "Sunday",
                      "Monday",
                      "Tuesday",
                      "Wednesday",
                      "Thursday",
                      "Friday",
                      "Saturday"  };
// 輸入
  scanf("%s", input);
  scanf("%d", &N);
// N = N + 星期幾
  if( strcmp(input,day[0])==0 )
    N += 0;
  if( strcmp(input,day[1])==0 )
    N += 1;
  if( strcmp(input,day[2])==0 )
    N += 2;
  if( strcmp(input,day[3])==0 )
    N += 3;
  if( strcmp(input,day[4])==0 )
    N += 4;
  if( strcmp(input,day[5])==0 )
    N += 5;
  if( strcmp(input,day[6])==0 )
    N += 6;
// N天後是星期幾
  N %= 7;
// 輸出
  printf("%s\n", day[N]);
  return 0;
}
