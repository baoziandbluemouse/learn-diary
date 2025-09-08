#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
struct node
{
    int cnt;
    ll val;
    bool operator<(const node &a) const
    {
        return (cnt == a.cnt) ? (val < a.val) : (cnt < a.cnt);
    }
};
node a[N];
ll prefix[N]; // 前缀和数组prefix
int main()
{
    int n;
    ll s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].val >> a[i].cnt;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i)
    {
        prefix[i] = prefix[i - 1] + a[i].val;
    }
    ll ans = 0, sc = 0; // sc存已训练次数
    for (int i = 1; i <= n; ++i)
    {
        if (prefix[n] - prefix[i - 1] > s)
        {
            a[i].cnt = a[i].cnt - sc;
            ans += s * a[i].cnt;
            sc += a[i].cnt;
        }
        else
        {
            a[i].cnt = a[i].cnt - sc;
            ans += a[i].val * a[i].cnt;
        }
    }
    cout << ans << "\n";
    return 0;
}