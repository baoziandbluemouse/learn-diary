#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int MOD = 998244353;
ll n, k;
ll w[65], tot; // w用于记录二进制化的N，tot则是总位数
PII dp[65][2][65];
// first用于记录当前位数右边有多少个符合条件的分支，second用于记录这些分支贡献的值总和
PII dfs(ll step, bool lim, ll cnt)
{
    // lim表示当前是否是受限状态，cnt表示当前1的个数
    // 我们从高位往低位搜，cnt=k则是一个符合条件的，超出边界那么不算贡献
    if (step == 0)
    {
        return {cnt == k, 0};
    }
    if (dp[step][lim][cnt].first > -1)
    {
        return dp[step][lim][cnt];
    }
    int up = 1; // up表示当前数位所能搜到的最大值
    // 如果在受限状态就只能填w[step]
    if (lim)
        up = w[step];
    ll c = 0, s = 0;
    // c表示符合条件的个数，s是贡献总和
    for (int i = 0; i <= up; i++)
    {
        PII t = dfs(step - 1, lim && i == up, cnt + (i == 1));
        c += t.first;
        c %= MOD;
        s += t.second;
        if (i == 1)
        {
            // 假如当前位数为1，产生了贡献，那么这个贡献产生的次数就是右边符合条件的分支个数
            // 贡献值就是2^ step-1
            s += (1ll << step - 1) % MOD * t.first % MOD;
        }
        s %= MOD;
    }
    // 存储，记忆化
    dp[step][lim][cnt] = {c, s};
    return {c, s};
}

void solve()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    tot = 0;
    while (n)
    {
        w[++tot] = n % 2;
        n /= 2;
    }
    cout << dfs(tot, 1, 0).second << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}