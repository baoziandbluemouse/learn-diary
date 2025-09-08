#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll x;
    cin >> x;
    if (x < 0)
    {
        cout << "No" << "\n";
        return;
    }
    string s = to_string(x);
    int n = s.size();
    if (n == 1)
    {
        cout << "Yes" << "\n";
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
            {
                cout << "No" << "\n";
                return;
            }
        }
        cout << "Yes" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}