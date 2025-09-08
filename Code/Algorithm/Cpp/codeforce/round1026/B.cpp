#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    stack<char> stk;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            stk.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (stk.size() && stk.top() == '(')
            {
                stk.pop();
            }
            if (stk.empty())
            {
                cnt++;
            }
        }
    }
    if (cnt > 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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