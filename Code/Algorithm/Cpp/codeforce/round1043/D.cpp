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
    ll n, k;
    cin >> n >> k;
    vector<ll> tr;
    ll min_k = 0;
    while (n)
    {
        tr.push_back(n % 3);
        min_k += n % 3;
        n /= 3;
    }
    if (min_k > k)
    {
        cout << -1 << "\n";
        return;
    }
    k -= min_k;
    k /= 2;
    for (int i = (int)tr.size() - 1; i >= 1; --i)
    {
        if (tr[i] <= k)
        {
            tr[i - 1] += 3 * tr[i];
            k -= tr[i];
            tr[i] = 0;
        }
        else
        {
            tr[i - 1] += k * 3;
            tr[i] -= k;
            break;
        }
    }
    ll an = 0;
    for (int i = (int)tr.size() - 1; i >= 0; --i)
        an += pre[i] * tr[i];
    cout << an << '\n';
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