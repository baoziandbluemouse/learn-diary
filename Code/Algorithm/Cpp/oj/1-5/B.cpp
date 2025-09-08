#include <bits/stdc++.h>
using namespace std;
#define MAX 260
typedef long long ll;
char str[MAX];
int main(void)
{
    stack<ll> stk;
    scanf("%[^\n]", str);
    int num = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '@')
        {
            cout << stk.top();
            break;
        }
        if (str[i] == ' ')
        {
            stk.push(num);
            num = 0;
            continue;
        }
        if (isdigit(str[i]))
        {
            num = num * 10 + str[i] - '0';
            continue;
        }
        if (str[i] == '+')
        {
            ll b = stk.top();
            stk.pop();
            ll a = stk.top();
            stk.pop();
            stk.push(a + b);
            continue;
        }
        if (str[i] == '-')
        {
            ll b = stk.top();
            stk.pop();
            ll a = stk.top();
            stk.pop();
            stk.push(a - b);
            continue;
        }
        if (str[i] == '*')
        {
            ll b = stk.top();
            stk.pop();
            ll a = stk.top();
            stk.pop();
            stk.push(a * b);
            continue;
        }
        if (str[i] == '/')
        {
            ll b = stk.top();
            stk.pop();
            ll a = stk.top();
            stk.pop();
            stk.push(a / b);
            continue;
        }
    }
    return 0;
}