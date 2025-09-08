#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
void solve()
{
    int n;
    cin >> n;
    int a[55] = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= i; j--)
        {
            if ((a[i] + a[j]) % 2 == 0)
            {
                ans = min(ans, n - (j - i + 1));
            }
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