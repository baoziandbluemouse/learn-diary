#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        else if (i + 1 < n && (a[i] ^ a[i + 1]) == b[i])
        {
            continue;
        }
        else if (i + 1 < n && (a[i] ^ b[i + 1]) == b[i])
        {
            continue;
        }
        cout << "NO\n";
        return;
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