#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;

void solve()
{
    stack<char> stk;
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{')
        {
            stk.push(c);
        }
        if (!stk.size() && (c == ')' || c == ']' || c == '}'))
        {
            cout << "NO" << '\n';
            return;
        }
        if (stk.size())
        {
            if (stk.top() == '(' && c == ')')
            {
                stk.pop();
            }
            else if (stk.top() == '{' && c == '}')
            {
                stk.pop();
            }
            else if (stk.top() == '[' && c == ']')
            {
                stk.pop();
            }
        }
    }
    if (stk.size())
    {
        cout << "NO" << '\n';
    }
    else
    {
        cout << "YES" << '\n';
    }
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}