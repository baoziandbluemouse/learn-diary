#include <iostream>
#include <string>
using namespace std;

void solve()
{
    string s;
    getline(cin, s);
    string ans;
    ans += s[0];
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            ans += s[i + 1];
            i++;
        }
        if (ans.size() == 3)
        {
            break;
        }
    }
    cout << ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        solve();
    }
    return 0;
}