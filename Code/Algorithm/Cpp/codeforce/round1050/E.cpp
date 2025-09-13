#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll res = 0;
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    int maxx = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    vector<int> b(maxx + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        b[a[i]]++;
    }
    for (int i = 1; i <= maxx; i++)
    {
        if (b[i] % k != 0)
        {
            cout << 0 << "\n";
            return;
        }
        b[i] = b[i] / k;
    }
    for (int i = 1, j = 1; i <= j && j <= n; j++)
    {
        while (i <= j && b[a[j]] == 0)
        {
            b[a[i]]++;
            i++;
        }
        b[a[j]]--;
        res += j - i + 1;
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