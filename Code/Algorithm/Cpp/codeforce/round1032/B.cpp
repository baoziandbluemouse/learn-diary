#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt1[26] = {0};
    int cnt2[26] = {0};
    for (int i = 0; i < n - 1; i++)
    {
        if (cnt1[s[i] - 'a'])
        {
            cout << "Yes\n";
            return;
        }
        cnt1[s[i] - 'a']++;
    }
    for (int i = n - 1; i > 0; i--)
    {
        if (cnt2[s[i] - 'a'])
        {
            cout << "Yes\n";
            return;
        }
        cnt2[s[i] - 'a']++;
    }
    cout << "No\n";
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