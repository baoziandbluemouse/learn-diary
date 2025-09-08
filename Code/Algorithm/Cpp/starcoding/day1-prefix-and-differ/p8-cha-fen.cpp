#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 9;
ll arr[N];
ll differ[N];
ll prefix[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p, q;
    ll x = 0, l = 0, r = 0;
    cin >> n >> p >> q;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        differ[i] = arr[i] - arr[i - 1]; // 差分处理
    }

    while (p--)
    {
        cin >> l >> r >> x;
        differ[l] += x;
        differ[r + 1] -= x; // 修改区间
    }

    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + differ[i]; // 通过差分还原数组，并且数据经过修改
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i]; // 前缀和
    }

    while (q--)
    {
        cin >> l >> r;
        ll res = 0;
        res = prefix[r] - prefix[l - 1];
        cout << res << '\n';
    }
    return 0;
}