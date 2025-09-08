#include <bits/stdc++.h>
using namespace std;
const int N = 110;

void solve()
{
    map<string, int> mp;
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        if (mp.count(s))
        {
            mp[s]++;
        }
        else
        {
            v.push_back(s);
            mp[s] = 1;
        }
    }
    for (auto &i : v)
    {
        cout << i << " " << mp[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}