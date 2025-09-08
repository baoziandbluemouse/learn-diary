#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    sort(cnt.begin(), cnt.end());
    for (int i = 0; i < 25; i++)
    {
        if (cnt[i] == 0)
        {
            continue;
        }
        if (cnt[i + 1] != cnt[i] + 1)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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