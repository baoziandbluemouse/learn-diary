#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (b + (a / 160) >= 160)
    {
        cout << "YES" << "\n";
    }
    else
    {
        int cnt = 160 - b - (a / 160);
        int ans = cnt * 160 - (a % 160);
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}