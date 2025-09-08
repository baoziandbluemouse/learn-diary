#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll qmi(ll a, ll b, ll c)
{
    ll res = 1;
    while (b != 0)
    {
        if (b & 1) // 如果b的二进制最后一位为1
        {
            res = res * a % c;
        }
        a = a * a % c; // 每次循环a都要翻倍
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll a, b, c;
    cin >> a >> b >> c;
    cout << qmi(a, b, c) << "\n";
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}