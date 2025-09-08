#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2)
    {
        if (s == "AB")
        {
            cout << "Alice" << "\n";
        }
        else if (s == "BA")
        {
            cout << "Bob" << "\n";
        }
    }
    else
    {
        if (s[0] == s[n - 1])
        {
            if (s[0] == 'A')
            {
                cout << "Alice" << "\n";
            }
            else if (s[0] == 'B')
            {
                cout << "Bob" << "\n";
            }
        }
        else
        {
            if (s[0] == 'A' && s[n - 1] == 'B')
            {
                for (int i = 0; i < n - 1; i++)
                {
                    if (s[i] == 'B')
                    {
                        cout << "Bob" << "\n";
                        return;
                    }
                }
                cout << "Alice" << "\n";
            }
            else if (s[0] == 'B' && s[n - 1] == 'A')
            {
                if (s[n - 2] == 'B')
                {
                    cout << "Bob" << "\n";
                    return;
                }
                else if (s[n - 2] == 'A')
                {
                    cout << "Alice" << "\n";
                    return;
                }
            }
        }
    }
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