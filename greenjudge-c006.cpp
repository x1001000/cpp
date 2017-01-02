#include <iostream>
#include <queue>

int i, L=0, R=0, N, news[21];

using namespace std;
queue<int> Lq, Rq;

void LorR(int i)
{
    if (i==1)
    {
        Lq.push(i);
        L+=news[i];
        return;
    }
    if (i==2)
    {
        Rq.push(i);
        R+=news[i];
        return;
    }
    if (L==R)
    {
        Lq.push(i);
        L+=news[i]+10;
        return;
    }
    if (L < R)
    {
        Lq.push(i);
        L+=news[i]+10;
        return;
    }
    if (L > R)
    {
        Rq.push(i);
        R+=news[i]+10;
        return;
    }
}
int main()
{
// input
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> news[i];

// process
    for(i=1; i<=N; i++)
        LorR(i);

// output
    while(!Lq.empty())
    {
        cout << Lq.front() << " ";
        Lq.pop();
    }
    cout << L << endl;

    while(!Rq.empty())
    {
        cout << Rq.front() << " ";
        Rq.pop();
    }
    cout << R << endl;

    return 0;
}
