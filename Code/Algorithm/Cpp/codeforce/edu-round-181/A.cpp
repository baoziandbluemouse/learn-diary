#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    int cnt[26] = {0};
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'A']++;
    }
    for (int i = 25; i >= 0; i--)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            cout << (char)('A' + i);
        }
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