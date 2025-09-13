#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string a, b;
    cin >> a >> b;
    int n = a.size();
    if (a == b)
    {
        cout << n * 2 << "\n";
        return;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            res += 2;
        }
        else if (b[i] - a[i] > 1)
        {
            cout << res << "\n";
            return;
        }
        else
        {
            // a[i]+1=b[i]
            res++;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] == '9' && b[j] == '0')
                {
                    res++;
                }
                else
                {
                    cout << res << "\n";
                    return;
                }
            }
            break;
        }
    }
    cout << res << "\n";
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