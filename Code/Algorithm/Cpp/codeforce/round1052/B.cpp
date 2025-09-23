#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(m + 1, 0);
    vector<vector<int>> a(n + 1, vector<int>());
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
            p[x]++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (p[i] == 0)
        {
            cout << "NO\n";
            return;
        }
    }
    int tem = 0;
    for (int i = 1; i <= n; i++)
    {
        int ok = 1;
        for (auto &x : a[i])
        {
            p[x]--;
            if (p[x] == 0)
            {
                ok = 0;
                break;
            }
        }
        tem += ok;
        // 复原
        for (auto &x : a[i])
        {
            p[x]++;
        }
    }
    cout << (tem >= 2 ? "YES" : "NO");
    cout << "\n";
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