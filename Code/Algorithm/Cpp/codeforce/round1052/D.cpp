#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int l, r;
    cin >> l >> r;
    vector<int> a(r - l + 1);
    for (int i = 0; i < a.size(); i++)
        a[i] = i + l;
    int l0 = l, r0 = r;
    for (int i = 30; i >= 0 && l0 <= r0; i--)
        if ((l0 ^ r0) >> i & 1)
        {
            int x = ((l0 >> i) << i) | ((1 << i) - 1), y = x + 1;
            while (l0 <= x && y <= r0)
            {
                swap(a[x - l], a[y - l]);
                x--, y++;
            }
            if (x < l0)
                l0 = y;
            else
                r0 = x;
        }
    ll ans = 0;
    for (int i = 0; i < r - l + 1; i++)
        ans += (i + l) | a[i];
    cout << ans << '\n';
    for (int i = 0; i < r - l + 1; i++)
        cout << a[i] << " \n"[i + 1 == r - l + 1];
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