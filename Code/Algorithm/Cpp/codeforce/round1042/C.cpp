#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    map<int, int> c;
    for (int x : a)
    {
        c[x % k]++;
    }
    for (int x : b)
    {
        if (c[x % k] > 0)
        {
            c[x % k]--;
        }
        else if (c[(k - x % k) % k] > 0)
        {
            c[(k - x % k) % k]--;
        }
        else
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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