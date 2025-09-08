#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, a[N];
void solve()
{
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        a[i] = a[i - 1];
        // a就是前缀和数组
        if (ch == '1')
        {
            a[i]++;
            cnt++;
        }
    }
    if (cnt == 0 || cnt == n)
    {
        cout << 0 << "\n";
        return;
    }
    int maxn = 0, ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int x = i - 2 * a[i];
        ans = min(ans, cnt + x - maxn);
        maxn = max(maxn, x);
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