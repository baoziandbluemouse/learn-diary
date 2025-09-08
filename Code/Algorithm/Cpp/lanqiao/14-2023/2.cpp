#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 2023;
ll a[2025];

ll qmi(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1 == 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int main()
{
    a[1] = 1;
    a[2] = 2;
    for (int i = 3; i <= 2023; i++)
    {
        a[i] = qmi(a[i - 1], i);
    }
    cout << a[2023] % mod << "\n";
    return 0;
}