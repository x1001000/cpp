#include <iostream>
#define coordinate pair<float, float>
#define x first
#define y second
using namespace std;
coordinate P[20000];
bool intersect(coordinate A, coordinate B, coordinate C, coordinate D)
{
  float L1 = (A.y - B.y)*C.x - (A.x - B.x)*C.y;
  float L2 = (A.y - B.y)*D.x - (A.x - B.x)*D.y;
  if ( L1 * L2 > 0) return false;
  return true;
}

int main()
{
  for()

  return 0;
}
