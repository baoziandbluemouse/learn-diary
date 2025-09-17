#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int s1 = pre[i] % 3;
            int s2 = (pre[j] - pre[i]) % 3;
            int s3 = (pre[n] - pre[j]) % 3;
            if ((s1 == s2 && s2 == s3) || (s1 != s2 && s2 != s3 && s1 != s3))
            {
                cout << i << " " << j << "\n";
                return;
            }
        }
    }
    cout << 0 << " " << 0 << "\n";
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