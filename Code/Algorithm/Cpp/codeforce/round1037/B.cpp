#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0;
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            if (temp % (k + 1) == k)
            {
                ans++;
            }
            ans = ans + temp / (k + 1);
            temp = 0;
        }
        else
        {
            temp++;
        }
    }
    if (temp != 0)
    {
        if (temp % (k + 1) == k)
        {
            ans++;
        }
        ans = ans + temp / (k + 1);
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