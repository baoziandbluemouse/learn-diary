#include <bits/stdc++.h>
using namespace std;

stack<int> stk;
string s;

void cal(int i)
{
    if (stk.empty())
    {
        return;
    }
    int a = stk.top();
    stk.pop();
    int b = stk.top();
    stk.pop();
    char c = s[i];
    if (c == '+')
    {
        stk.push(b + a);
    }
    else if (c == '-')
    {
        stk.push(b - a);
    }
    else if (c == '*')
    {
        stk.push(b * a);
    }
    else if (c == '/')
    {
        stk.push(b / a);
    }
}

int main()
{
    cin >> s;
    int len = s.size();
    int a = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '@')
        {
            break;
        }
        else if (s[i] == '.')
        {
            stk.push(a);
            a = 0;
        }
        else if (s[i] >= '0' && s[i] <= '9')
        {
            a = a * 10 + (s[i] - '0');
        }
        else
        {
            cal(i);
        }
    }
    cout << stk.top() << "\n";
    return 0;
}