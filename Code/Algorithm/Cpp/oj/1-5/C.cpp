#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5 + 5;
char str[MAX];
bool isright(char *str);             // 检查合法
void getbehind(char *str);           // 获取后缀表达式，然后计算
void getnum(char c, stack<ll> &stk); // 计算函数
int main(void)
{
    cin >> str;
    if (!isright(str))
    {
        cout << "NO\n";
    }
    getbehind(str);
    return 0;
}

bool isright(char *str)
{
    stack<char> check;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (i == 0)
        {
            if (isdigit(str[i]))
            {
                continue;
            }
            else if (str[i] == '(')
            {
                check.push(str[i]);
                continue;
            }
            else
            {
                return false;
            }
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
        {
            if (isdigit(str[i + 1]))
            {
                continue;
            }
            else if (str[i + 1] == '(')
            {
                check.push(str[i]);
                continue;
            }
            else
            {
                return false;
            }
        }
        if (str[i] == '(')
        {
            if (!isdigit(str[i + 1]))
            {
                return false;
            }
            check.push(str[i]);
            continue;
        }
        if (str[i] == ')')
        {
            if (isdigit(str[i + 1]))
            {
                return false;
            }
            if (check.empty())
            {
                return false;
            }
            check.pop();
        }
    }
    if (check.empty())
        return true;
    else
        return false;
}

void getbehind(char *str)
{
    stack<char> sig;
    ll num = 0;
    stack<ll> res;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (isdigit(str[i]))
        {
            num = num * 10 + str[i] - '0';
        }
        else
        {
            if (num != 0)
            {
                res.push(num);
                num = 0;
            }
            if (str[i] == '(')
            {
                sig.push(str[i]);
                continue;
            }
            if (str[i] == '+' || str[i] == '-')
            {
                while (!sig.empty() && sig.top() != '(')
                {
                    getnum(sig.top(), res);
                    sig.pop();
                }
                sig.push(str[i]);
                continue;
            }
            if (str[i] == '*' || str[i] == '/')
            {
                if (sig.top() == '*' || sig.top() == '/')
                {
                    getnum(sig.top(), res);
                    sig.pop();
                }
                sig.push(str[i]);
                continue;
            }
            if (str[i] == ')')
            {
                while (sig.top() != '(')
                {
                    getnum(sig.top(), res);
                    sig.pop();
                }
            }
        }
    }
    while (!sig.empty())
    {
        getnum(sig.top(), res);
        sig.pop();
    }
    cout << res.top();
}

void getnum(char c, stack<ll> &stk)
{
    if (c == '+')
    {
        ll b = stk.top();
        stk.pop();
        ll a = stk.top();
        stk.pop();
        stk.push(a + b);
    }
    if (c == '-')
    {
        ll b = stk.top();
        stk.pop();
        ll a = stk.top();
        stk.pop();
        stk.push(a - b);
    }
    if (c == '*')
    {
        ll b = stk.top();
        stk.pop();
        ll a = stk.top();
        stk.pop();
        stk.push(a * b);
    }
    if (c == '/')
    {
        ll b = stk.top();
        stk.pop();
        ll a = stk.top();
        stk.pop();
        stk.push(a / b);
    }
}