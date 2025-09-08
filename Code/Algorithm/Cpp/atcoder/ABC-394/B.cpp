#include <bits/stdc++.h>
using namespace std;
map<int, string> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mp[s.length()] = s;
    }
    string ans;
    int first = 1;
    for (auto &p : mp)
    {
        if (first)
        {
            ans = p.second;
            first = 0;
        }
        else
        {
            ans = ans + p.second;
        }
    }
    cout << ans << "\n";
    return 0;
}