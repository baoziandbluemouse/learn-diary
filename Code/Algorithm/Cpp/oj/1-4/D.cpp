#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAX = 1e18;
const ll N = 1e5 + 7;
ll L, k, a[N], ans1 = -1, ans2 = -1;
bool check1(ll mid, ll sum, ll cnt);
ll merge1(ll l, ll r);
bool check2(ll mid, ll sum, ll cnt);
ll merge2(ll l, ll r);
bool check(ll ans)
{
    ll sum = 0;
    ll cnt = 0;
    for (int i = 1; i <= L; i++)
    {
        if (sum + a[i] < 0)
        {
            sum = 0;
            continue;
        }
        sum += a[i];
        if (sum >= ans)
        {
            sum = 0;
            cnt++;
        }
    }
    if (cnt == k)
    {
        return true;
    }
    return false;
}
int main(void)
{
    cin >> L >> k;
    for (int i = 1; i <= L; i++)
    {
        cin >> a[i];
    }

    ans1 = merge1(0, MAX);
    ans2 = merge2(0, MAX);
    if (check(ans1) && check(ans2))
    {
        cout << ans1 << " " << ans2 << "\n";
    }
    else
    {
        cout << "-1\n";
    }

    return 0;
}

bool check1(ll mid, ll sum, ll cnt)
{
    for (int i = 1; i <= L; i++)
    {
        if (sum + a[i] < 0)
        {
            sum = 0;
            continue;
        }
        sum += a[i];
        if (sum >= mid)
        {
            sum = 0;
            cnt++;
        }
    }
    if (cnt <= k)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ll merge1(ll l, ll r)
{
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;
        ll sum = 0;
        ll cnt = 0;
        if (check1(mid, sum, cnt))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return r;
}

bool check2(ll mid, ll sum, ll cnt)
{
    for (int i = 1; i <= L; i++)
    {
        if (sum + a[i] < 0)
        {
            sum = 0;
            continue;
        }
        sum += a[i];
        if (sum >= mid)
        {
            sum = 0;
            cnt++;
        }
    }
    if (cnt >= k)
    {
        return true;
    }
    return false;
}

ll merge2(ll l, ll r)
{
    while (l + 1 < r)
    {
        ll mid = l + (r - l) / 2;
        ll sum = 0;
        ll cnt = 0;
        if (check2(mid, sum, cnt))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    return l;
}