#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve()
{
    ll d, m;
    cin >> d >> m;
    if (m % d != 0)
    {
        cout << 0 << "\n";
        return;
    }
    m = m / d;
    ll cnt = 0;
    for (ll i = 2; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            cnt++;
            while (m % i == 0)
            {
                m /= i;
            }
        }
    }
    if (m > 1)
    {
        cnt++;
    }
    cout << (1 << cnt) << "\n";
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