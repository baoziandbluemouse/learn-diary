#include <bits/stdc++.h>
using namespace std;
const int P = 998244353;
using ll = long long;
const int N = 1e5 + 5;
ll p[N], q[N];
ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = res * a % P;
        }
        a = a * a % P;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
    }
    ll m1 = 0, m2 = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (p[m1] < p[i])
            m1 = i;
        if (q[m2] < q[i])
            m2 = i;
        if (p[m1] > q[m2] || (p[m1] == q[m2] && q[i - m1] > p[i - m2]))
        {
            cout << (qmi(2, p[m1]) + qmi(2, q[i - m1])) % P << " ";
        }
        else
        {
            cout << (qmi(2, q[m2]) + qmi(2, p[i - m2])) % P << " ";
        }
    }
    cout << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}