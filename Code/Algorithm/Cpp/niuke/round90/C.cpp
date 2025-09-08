#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
// const int N = 2e5 + 10;
const int N = 100;
struct node
{
    ll val;
    int idx;
    bool operator<(const node &b) const
    {
        if (val != b.val)
        {
            return val > b.val;
        }
        else
        {
            return idx > b.idx;
        }
    }
};

bool cmp(ll a, ll b)
{
    return a > b;
}
ll a[N], b[N];
node c[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        c[i].val = a[i] * i;
        c[i].idx = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(c + 1, c + n + 1);
    sort(b + 1, b + n + 1, cmp);
    vector<ll> ans(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        ans[c[i].idx] = b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}
