#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct node
{
    int l;
    int r;
    int val;
    bool operator<(const node &b) const
    {
        if (val != b.val)
        {
            return val < b.val;
        }
        else if (l != b.l)
        {
            return l < b.l;
        }
        else
        {
            return r < b.r;
        }
    }
};
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<node> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].l >> a[i].r >> a[i].val;
    }
    sort(a.begin(), a.end());
    for (auto &t : a)
    {
        if (k >= t.l && k <= t.r)
        {
            k = max(k, t.val);
        }
    }
    cout << k << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}