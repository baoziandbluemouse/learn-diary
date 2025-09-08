#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 5);
    vector<int> b(m + 5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int pa = 1, pb = 1;
    int ans = 0;
    while (pa <= n)
    {
        int cna = 0, cnb = 0;
        int t = a[pa];
        while (pb <= m && b[pb] == t)
        {
            cnb++;
            pb++;
        }
        while (pa <= n && a[pa] == t)
        {
            cna++;
            pa++;
        }
        if (cnb < cna)
        {
            cout << -1 << "\n";
            return;
        }
        int ta = 0;
        while (cnb > cna)
        {
            cna <<= 1;
            ta++;
        }
        ans = max(ans, ta);
    }
    if (pb <= m)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
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