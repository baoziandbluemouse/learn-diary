#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    int pos = len - 1;
    while (s[pos] == '0')
    {
        pos--;
        ans++;
    }
    for (int i = 0; i < pos; i++)
    {
        if (s[i] != '0')
        {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}