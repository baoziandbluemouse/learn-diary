#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    ll res = 0;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    res += m - a[n];
    bool flag = false;
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = a[i], dis = b[i];
        if (flag)
        {
            if ((a[i] % 2 == 0 && b[i] == 1) || (a[i] % 2 != 0 && b[i] == 0))
            {
                res += a[i] - cur;
                cur = a[i];
            }
            else
            {
                cur++;
                flag = false;
                res += a[i] - cur;
                cur = a[i];
            }
        }
        else
        {
            if ((a[i] % 2 == 0 && b[i] == 0) || (a[i] % 2 != 0 && b[i] == 1))
            {
                res += a[i] - cur;
                cur = a[i];
            }
            else
            {
                cur++;
                flag = true;
                res += a[i] - cur;
                cur = a[i];
            }
        }
    }
    cout << res << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}