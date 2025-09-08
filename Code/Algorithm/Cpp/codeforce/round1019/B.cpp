#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int ans = 0;
    char cur = '0';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == cur)
        {
            ans++;
        }
        else
        {
            cur = s[i];
            ans += 2;
            cnt++;
        }
    }
    if (cnt <= 1)
    {
        cout << ans << "\n";
    }
    else if (cnt == 2)
    {
        cout << ans - 1 << "\n";
    }
    else
    {
        cout << ans - 2 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}