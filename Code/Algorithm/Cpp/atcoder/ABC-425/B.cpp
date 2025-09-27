#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> b(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] != -1)
        {
            b[a[i]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > 1)
        {
            cout << "No\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == -1)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[j] == 0)
                {
                    a[i] = j;
                    b[j]++;
                    break;
                }
            }
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}