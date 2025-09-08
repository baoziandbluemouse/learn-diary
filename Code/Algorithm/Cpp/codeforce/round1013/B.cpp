#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if (p >= x)
            ans++;
        else
            a.push_back(p);
    }
    sort(a.begin(), a.end(), greater<int>());
    int cnt = 0;
    for (auto &j : a)
    {
        cnt++;
        int need = (x + j - 1) / j;
        if (cnt >= need)
        {
            ans++;
            cnt -= need;
        }
    }
    cout << ans << "\n";
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