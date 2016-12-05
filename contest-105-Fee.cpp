#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n, fee=0;
  cin >> n;
  int point[n];
  for(int i=0; i<n; i++)
    cin >> point[i];
  sort(point, point+n);
  int points = point[0];
  for(int i=1; i<n; i++)
  {
    points += point[i];
    fee += points;
  }
  cout << fee;
  return 0;
}
