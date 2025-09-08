#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(a[i]);
    }
    cout << ans << "\n";
}

int main()
{
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}