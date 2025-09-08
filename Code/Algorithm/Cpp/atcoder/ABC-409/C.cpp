#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
using ll = long long;
ll d[N], a[N], cnt[N];
int main()
{
    int l, n;
    cin >> n >> l;
    cnt[0] = 1; // 第1个点要记得记录
    for (int i = 2; i <= n; i++)
    {
        cin >> d[i];
        a[i] = (a[i - 1] + d[i]) % l;
        cnt[a[i]]++;
    }
    if (l % 3 != 0)
    {
        cout << 0;
        return 0;
    }
    int x = l / 3;
    ll res = 0;
    for (int i = 0; i < x; i++)
    {
        res += 1ll * cnt[i] * cnt[i + x] * cnt[i + 2 * x];
    }
    cout << res;
    return 0;
}