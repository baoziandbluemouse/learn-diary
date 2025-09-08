#include <cstdio>
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
#define N 60
const ll MAX = 1e10;
int n;
ll a[N], m;
bool check(ll mid);
ll maxx(ll a, ll b);
ll minn(ll a, ll b);
int main(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll l = -1;
    ll r = MAX;
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}

bool check(ll mid)
{
    ll k = 0;
    for (int i = 1; i <= n; i++)
    {
        k += maxx(0, mid - a[i]);
    }
    if (k <= minn(m, mid))
    {
        return true;
    }
    return false;
}

ll minn(ll a, ll b)
{
    return a < b ? a : b;
}

ll maxx(ll a, ll b)
{
    return a > b ? a : b;
}