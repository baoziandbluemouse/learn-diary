#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> pre;
int cnt;
ll qmi(ll a, int b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

void init()
{
    pre.emplace_back(3);
    cnt++;
    int t = 1;
    while (qmi(3, t) <= 1e9)
    {
        ll cos = qmi(3, t + 1) + t * qmi(3, t - 1);
        pre.emplace_back(cos);
        cnt++;
        t++;
    }
}

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    int temp = cnt;
    while (n)
    {
        while (qmi(3, temp) <= n)
        {
            n -= qmi(3, temp);
            ans += pre[temp];
        }
        temp--;
    }
    cout << ans << "\n";
}

int main()
{
    int _;
    cin >> _;
    init();
    while (_--)
    {
        solve();
    }
    return 0;
}