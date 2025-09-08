#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a;
ll n;

int cal(int x)
{
    int res = 1;
    while (x)
    {
        res *= 10;
        x /= 10;
    }
    return res;
}

int rev(int x)
{
    int res = 0;
    while (x)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

bool check(ll x)
{
    string s;
    while (x)
    {
        s += x % a + '0';
        x /= a;
    }
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

void solve()
{
    cin >> a >> n;
    ll sum = 0;
    for (int i = 1; i <= 1e6; i++)
    {
        int base = cal(i);
        int rx = rev(i);
        ll num = (ll)i * base + (ll)rx;
        if (num <= n && check(num))
            sum += num;
        num = (ll)(i / 10) * base + (ll)rx;
        if (num <= n && check(num))
            sum += num;
    }
    cout << sum << "\n";
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