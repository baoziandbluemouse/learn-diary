#include <iostream>
#include <string>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            cout << "l";
        }
        else if (s[i] == 'l')
        {
            cout << "I";
        }
        else
        {
            cout << s[i];
        }
    }
    cout << "\n";
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