#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
ll a[N];
int len(ll x)
{
    int res = 0;
    while (x)
    {
        res++;
        x /= 10;
    }
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll t = 1;
    for (int i = 1; i <= k; i++)
    {
        t *= 10;
    }
    t--;
    ll ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (t / a[i] < ans)
        {
            ans = 1;
        }
        else
        {
            ans *= a[i];
        }
    }
    cout << ans << "\n";
    return 0;
}