#include <iostream>
#include <bitset>
#include <vector>    //http://mropengate.blogspot.tw/2015/07/cc-vector-stl.html
#include <algorithm>

using namespace std;

const int N = 1000001;
vector<int> prime, ans;
bitset<N> pr;

bool solve(int i, int prv) {
    if (!i) return true;
    for (auto k = lower_bound(prime.begin(), prime.end(), min(i, prv - 1), greater<int>()); ~*k; k++) {
        if (solve(i - *k, *k)) {
            ans.push_back(*k);
            return true;
        }
    }
    return false;
}

int main()
{
    pr.set(1);
    for (int i = 2; i < N; i++) {
        if (!pr[i]) prime.push_back(i);
        for (int& a : prime) {
            if (a * i >= N) break;
            pr.set(a * i);
            if (!(i % a)) break;
        }
    }
    reverse(prime.begin(), prime.end());
    prime.push_back(-1);

    int q, a;
    cin >> q;

    while (q--) {
        cin >> a;
        if (pr[a]) cout << "0\n";
        else {
            ans.clear();
            if (solve(a, a))
                for (auto i = ans.rbegin(); i != ans.rend(); i++) cout << *i << ' ';
            else cout << a;
            cout << endl;
        }
    }
}
