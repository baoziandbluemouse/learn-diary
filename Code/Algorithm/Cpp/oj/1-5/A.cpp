#include <bits/stdc++.h>
using namespace std;

char n;

int main(void)
{
    stack<char> stk;
    while (cin >> n)
    {
        if (stk.empty())
        {
            if (n == ')' || n == ']')
            {
                cout << "Wrong\n";
                return 0;
            }
        }
        if (n == '(' || n == '[')
            stk.push(n);
        else if (n == ')')
        {
            if (stk.top() == '(')
            {
                stk.pop();
            }
            else
            {
                cout << "Wrong\n";
                return 0;
            }
        }
        else if (n == ']')
        {
            if (stk.top() == '[')
            {
                stk.pop();
            }
            else
            {
                cout << "Wrong\n";
                return 0;
            }
        }
    }
    if (stk.empty())
        cout << "OK\n";
    else
        cout << "Wrong\n";
    return 0;
}