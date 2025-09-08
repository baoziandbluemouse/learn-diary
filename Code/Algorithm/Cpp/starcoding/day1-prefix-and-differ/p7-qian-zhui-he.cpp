#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n, q;
    cin >> t;
    while (t--)
    {
        vector<ll> arr(100010);
        vector<ll> sum(100010);
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        sum[1] = arr[1];
        for (int i = 2; i <= n; i++)
        {
            sum[i] = sum[i - 1] + arr[i]; // 前缀和处理
        }
        int l = 0, r = 0;
        while (q--)
        {
            cin >> l >> r;
            ll res = sum[r] - sum[l - 1];
            cout << res << '\n';
        }
    }
    return 0;
}