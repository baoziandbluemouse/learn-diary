#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
using ll = long long;
int a[N];
void solve()
{
    int n, r, ans = 0;
    cin >> n >> r;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int le = 1, re = n;
    while (a[le] == 1)
        le++; // 找到最左边的0
    while (a[re] == 1)
        re--; // 找到最右边的0
    for (int i = min(le, r + 1); i <= max(r, re); i++)
        ans += a[i] + 1;
    cout << ans;
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}