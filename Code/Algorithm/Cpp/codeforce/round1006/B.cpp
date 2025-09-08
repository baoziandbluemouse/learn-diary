#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (n < 3)
    {
        cout << 0 << "\n";
        return;
    }
    ll cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '_')
        {
            cnt1++;
        }
        else if (s[i] == '-')
        {
            cnt2++;
        }
    }
    ll ans = (cnt2 * cnt2) / 4;
    cout << ans * cnt1 << "\n";
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