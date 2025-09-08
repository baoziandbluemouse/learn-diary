#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
const int MOD = 998244353;
int n, x, ans, cnt[N];

struct node
{
    int z, id;
};

bool cmp(node x, node y)
{
    return x.z > y.z;
}

vector<node> v;
int inv(int a)
{
    int b = MOD - 2, res = 1;
    while (b)
    {
        if (b % 2)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 6;
        // 第i个骰子有多少个面<=x,x会变动
        for (int j = 1; j <= 6; j++)
        {
            cin >> x;
            v.push_back({x, i});
        }
    }
    int p = 1;
    sort(v.begin(), v.end(), cmp);
    for (auto &i : v)
    {
        ans += i.z * p % MOD * inv(cnt[i.id]) % MOD;
        ans %= MOD;
        p = p * inv(cnt[i.id]) % MOD;
        cnt[i.id]--;
        p = p * cnt[i.id] % MOD;
    }
    cout << ans << "\n";
    return 0;
}