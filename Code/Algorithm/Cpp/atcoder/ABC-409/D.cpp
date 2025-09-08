#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] > s[i + 1])
        {
            cout << s.substr(0, i);
            for (int j = i + 2; j < n; j++)
            {
                if (s[j] > s[i])
                {
                    cout << s.substr(i + 1, j - i - 1);
                    cout << s[i] << s.substr(j) << "\n";
                    return;
                }
            }
            cout << s.substr(i + 1);
            cout << s[i] << "\n";
            return;
        }
    }
    cout << s << "\n";
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