#include <bits/stdc++.h>
using namespace std;

int cal(string a, int i)
{
    if (a[i] == '0')
    {
        a[i] = '1';
    }
    else
    {
        a[i] = '0';
    }
    int n = a.size();
    int res = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == '1')
        {
            res++;
        }
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += cal(a, i);
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}