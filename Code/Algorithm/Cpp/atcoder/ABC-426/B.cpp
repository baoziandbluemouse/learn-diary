#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int a[N];
void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        a[s[i] - 'a']++;
    }
    for (int i = 0; i <= 25; i++)
    {
        if (a[i] == 1)
        {
            cout << (char) ('a' + i) << "\n";
            return;
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