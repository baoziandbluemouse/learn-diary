#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (ans == -1)
        {
            if (a[i])
            {
                ans = a[i];
            }
        }
        else
        {
            if (a[i])
            {
                ans = -1;
                break;
            }
        }
    }
    if (ans != -1)
    {
        cout << ans << "\n";
        return;
    }

    int maxx = -1;
    for (int i = 1; i <= n; i++)
    {
        maxx = max(maxx, a[i]);
    }
    for (int i = maxx; i >= 1; i--)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] >= i)
            {
                cnt++;
            }
        }
        ans = max(ans, cnt * i);
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