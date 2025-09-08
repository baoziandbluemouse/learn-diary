#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 2; i <= n / i; i++) // 枚举所有质因子 i肯定要从2开始
    {
        if (n % i != 0)
        {
            continue;
        }
        // i为一个质因子
        v.push_back(i);
        while (n % i == 0)
        {
            n /= i; // n除去所有i
        }
    }
    if (n > 1)
    {
        v.push_back(n); // 如果n>1,最后n他自己就是一个质因子
    }
    sort(v.begin(), v.end());
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}