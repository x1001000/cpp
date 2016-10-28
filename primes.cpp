#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N; //輸入要算出是否為質數的最大正整數

    bool not_a_prime[ N + 1 ];
    for (int i = 0; i < N + 1; i++) //從0到N都設為質數
        not_a_prime[ i ] = false;

    vector<int> primes; //用vector<int>宣告長度未定的整數串primes

    for (int i = 2; i <= N; i++) //i從2到N走一遍
    {
        if (not_a_prime[i] == false) //若i是質數就把i接到primes串的後面
            primes.push_back(i);
        for (int j = 0; j < primes.size(); j++) //primes串走一遍
        {
            if (i * primes.at(j) > N) //若i乘以primes串裡面的質數超過N了就跳出
                break;
            not_a_prime[ i * primes.at(j) ] = true; //將i乘以primes串裡面的質數的結果設為非質數
        }
    }

    for (int i = 0; i < primes.size(); i++) //印出primes串
        cout << primes.at(i) << endl;

    return 0;
}
