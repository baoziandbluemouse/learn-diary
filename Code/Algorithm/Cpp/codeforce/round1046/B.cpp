#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = " " + s;
    int c1 = 0, c2 = 0;
    for (int i = 1, j = 1; i <= n; i = ++j)
    {
        if (s[i] == '1')
        {
            c2++;
            while (j < n && s[j + 1] == '1')
            {
                c2++;
                j++;
            }
            if (j - i + 1 >= k)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++)
    {
        cout << (s[i] == '1' ? ++c1 : ++c2) << " ";
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