#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 2)
    {
        if (a[1] == a[2])
        {
            cout << "YES" << "\n";
        }
        else
        {
            cout << "NO" << "\n";
        }
    }
    else
    {
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != 1)
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << "YES" << "\n";
            return;
        }
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i + 1] && a[i] == 0)
            {
                cout << "YES" << "\n";
                return;
            }
        }
        cout << "NO" << "\n";
    }
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