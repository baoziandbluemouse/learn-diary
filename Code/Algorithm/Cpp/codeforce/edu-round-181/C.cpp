#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;
int qmi(int a, int b)
{
    int res = 1;
    if (b)
    {
        if (b & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res % MOD;
}

int inv(int a)
{
    return qmi(a, MOD - 2);
}

void solve()
{
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}