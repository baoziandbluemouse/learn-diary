#include <bits/stdc++.h>
using namespace std;
stack<char> stk;
bool flag = false;
void solve(char c)
{
    if (stk.empty() && (c == ']' || c == ')' || c == '>'))
    {
        flag = true;
        return;
    }
    if (c == ')')
    {
        if (stk.size() && stk.top() == '(')
        {
            stk.pop();
        }
        else
        {
            flag = true;
            return;
        }
    }
    else if (c == ']')
    {
        if (stk.size() && stk.top() == '[')
        {
            stk.pop();
        }
        else
        {
            flag = true;
            return;
        }
    }
    else if (c == '>')
    {
        if (stk.size() && stk.top() == '<')
        {
            stk.pop();
        }
        else
        {
            flag = true;
            return;
        }
    }
    else
    {
        stk.push(c);
    }
}

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        solve(s[i]);
        if (flag)
        {
            cout << "No" << "\n";
            return 0;
        }
    }
    if (stk.size())
    {
        cout << "No" << "\n";
    }
    else
    {
        cout << "Yes" << "\n";
    }
    return 0;
}