#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(10, 0);
    int ans = 0;
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
        if (!flag && a[0] >= 3 && a[1] >= 1 && a[2] >= 2 && a[3] >= 1 && a[5] >= 1)
        {
            flag = true;
            ans = i;
        }
    }
    cout << ans << "\n";
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