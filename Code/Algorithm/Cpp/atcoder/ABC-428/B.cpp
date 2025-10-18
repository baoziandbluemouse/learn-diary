#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<string, int> mp;
    string s;
    int n, k;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.size() - k + 1; i++)
    {
        string t = s.substr(i, k);
        mp[t]++;
    }
    int maxx = -1;
    for (auto &x : mp)
    {
        maxx = max(maxx, x.second);
    }
    cout << maxx << "\n";
    for (auto &x : mp)
    {
        if (x.second == maxx)
        {
            cout << x.first << " ";
        }
        else
        {
            continue;
        }
    }
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