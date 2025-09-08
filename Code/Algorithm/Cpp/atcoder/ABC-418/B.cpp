#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    double ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int x = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (s[j] == 't')
                x++;
            if (j - i + 1 >= 3)
                ans = max(ans, 1.0 * (x - 2) / (j - i + 1 - 2));
        }
    }
    cout << fixed << setprecision(10) << ans;
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