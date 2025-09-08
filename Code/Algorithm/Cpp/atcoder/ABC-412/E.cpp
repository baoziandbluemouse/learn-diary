#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7;
int pri[N], cnt; // primes[]存储所有素数
int minp[N];

void get_primes(int n)
{
    for (int i = 2; i <= n; i += 1)
    {
        if (!minp[i])
            pri[++cnt] = i, minp[i] = i;
        for (int j = 1; pri[j] * i <= n && j <= cnt; j++)
        {
            minp[pri[j] * i] = pri[j];
            if (minp[i] == pri[j])
                break;
        }
    }
}

int main()
{
    ll l, r;
    cin >> l >> r;
    get_primes(1e7);
    ll res = 1; // a[l]是第一个数字
    l++;        // 处理[l+1,r]里面的‘断点’
    for (int i = 1; i <= cnt && pri[i] <= r / pri[i]; i++)
    { // p^k出现在l之后
        ll p = pri[i];
        ll base = p * p;
        while (base <= r)
        {
            if (base > l)
                res++;
            base *= p;
        }
    }
    unordered_map<ll, bool> mp; // 标记非素数
    for (int i = 1; i <= cnt && pri[i] <= r / pri[i]; i++)
    { // 标记[l+1,r]里的非素数
        ll p = pri[i];
        ll st = (l + p - 1) / p * p;
        st = max(st, p * p);
        for (ll j = st; j <= r; j += p)
        {
            mp[j] = 1;
        }
    }
    res += (r - l + 1) - mp.size();
    cout << res;

    return 0;
}