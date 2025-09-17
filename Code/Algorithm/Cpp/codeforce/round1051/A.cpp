#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    int idx = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == idx)
        {
            idx = i;
            break;
        }
    }
    int i = idx, j = idx;
    bool flag = false;
    while (i >= 1 && j <= n)
    {
        if (i != 1 && a[i] > a[i - 1])
        {
            i--;
        }
        else if (i != 1)
        {
            flag = true;
            break;
        }
        if (j != n && a[j] > a[j + 1])
        {
            j++;
        }
        else if (j != n)
        {
            flag = true;
            break;
        }
        if (i == 1 && j == n)
        {
            break;
        }
    }
    if (flag)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
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