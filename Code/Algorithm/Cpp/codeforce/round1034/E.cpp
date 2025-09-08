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
    vector<int> c(n + 2, 0);
    for (int x : a)
    {
        c[x]++;
    }
    int mex = 0;
    while (c[mex])
        mex++;
    vector<int> d(n + 2, 0);
    for (int i = mex; i >= 0; i--)
    {
        int cnt1 = c[i];
        int cnt2 = n - i;
        if (cnt1 <= cnt2)
            d[cnt1]++, d[cnt2 + 1]--;
    }
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        cur += d[i];
        cout << cur << " ";
    }
    cout << "\n";
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