#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;
void solve()
{
    int x;
    cin >> x;
    bitset<32> b(x);
    for (int i = 0; i < 32; i++)
    {
        if (!b[i])
        {
            b.set(i);
        }
        ll y = b.to_ullong();
        ll ans = y - x;
        if (ans > x || ans <= 0)
        {
            continue;
        }
        else
        {
            cout << ans << "\n";
            return;
        }
    }
    cout << "-1\n";
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