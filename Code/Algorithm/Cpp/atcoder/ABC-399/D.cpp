#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n * 2 + 10, 0);
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a[i];
    }
    map<pair<int, int>, int> mp;
    int res = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if (mp.count({a[i], a[i + 1]})) // 如果相邻数对位置完全一致
        {
            res++;
        }
        else if (mp.count({a[i + 1], a[i]}) && i - mp[{a[i + 1], a[i]}] > 2)
        // 如果数对位置相反，由于记录的是前一个数的位置，所以间隔要大于2  a,b x b,a
        {
            res++;
        }

        mp[{a[i], a[i + 1]}] = i; // 记录a[i]的位置
    }
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}