#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;
vector<ll> a;
vector<ll> b;
ll pre[N];
bool cmp(ll x, ll y)
{
    return x > y;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 1; i <= m; i++)
    {
        ll x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    int len = min(n, m);
    for (int i = 0; i < len; i++)
    {
        pre[i] = a[i] + b[i];
    }
    ll ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (pre[i] > 0 && pre[i] > a[i])
        {
            if (a.size())
            {
                ans = ans + pre[i];
                a[i] = 0;
            }
        }
        else
        {
            break;
        }
    }
    for (auto &i : a)
    {
        if (i >= 0)
        {
            ans = ans + i;
        }
        else
        {
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}