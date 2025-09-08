#include <iostream>
using namespace std;
using ll = long long;
ll check(ll x)
{
    ll cnt = 0;
    while (x > 0)
    {
        cnt += x / 5;
        x /= 5;
    }
    return cnt;
}
int main()
{
    ll k;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    ll l = 0, r = 6e18;
    while (l + 1 < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid) >= k)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (check(r) == k)
    {
        cout << r << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }
    return 0;
}