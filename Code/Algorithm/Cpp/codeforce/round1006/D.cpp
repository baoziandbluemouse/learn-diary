#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = 1e8, l, r;
    for (int i = 0; i < n; i++)
    {
        int t1 = 0, t2 = 0;
        for (int j = i; j < n; j++)
        {
            if (a[j] > a[i])
            {
                t2++;
            }
            else if (a[j] < a[i])
            {
                t1++;
            }
            if (res > t2 - t1)
            {
                res = min(res, t2 - t1);
                l = i, r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << "\n";
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