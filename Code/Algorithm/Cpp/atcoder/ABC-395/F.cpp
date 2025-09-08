#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
ll u[N], d[N];
int n;
ll X;

bool check(ll mid)
{
    // l[i] = max(0,h-d[i])
    // r[i] = min(h,u[i])
    ll lstl = max(0ll, mid - d[1]); // 最开始的l
    ll lstr = min(mid, u[1]);
    for (int i = 2; i <= n; i++)
    {
        // max(h-d[i],0) <= u[i](修牙后) <= min(h,u[i])
        //  lstl - X <= u[i] <= lstr + X
        // 取交集
        lstl = max(lstl - X, max(0ll, mid - d[i]));
        lstr = min(lstr + X, min(mid, u[i]));
        if (lstl > lstr)
        {
            return false; // 空集，无解
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> X;
    ll l = -1, r = 2e9 + 1;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i] >> d[i];
        r = min(r, u[i] + d[i] + 1); // 缩小上界
        sum = sum + u[i] + d[i];
    }
    while (l + 1 != r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
        {
            l = mid; // h取越大越好，这样才能使sum - n * h最小
        }
        else
        {
            r = mid;
        }
    }
    cout << sum - n * l << "\n";
    return 0;
}