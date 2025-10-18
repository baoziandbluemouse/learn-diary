#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 10;
char stk[N];
int top = 0;

void solve()
{
    int q;
    cin >> q;
    int cnt = 0;
    bool err_flag = false;
    int wr_idx = -1;
    while (q--)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            char c;
            cin >> c;
            if (wr_idx != -1)
            {
                top++;
                continue;
            }
            if (c == '(')
            {
                if (wr_idx == -1)
                {
                    cnt++;
                }
                stk[++top] = c;
            }
            else
            {
                if (top == 0 || (stk[top] == ')' && cnt == 0))
                {
                    stk[++top] = c;
                    wr_idx = top;
                }
                else
                {
                    stk[++top] = c;
                    if (wr_idx == -1)
                    {
                        cnt--;
                    }
                }
            }
        }
        else
        {
            if (wr_idx != -1)
            {
                top--;
                if (top < wr_idx)
                {
                    wr_idx = -1;
                }
                continue;
            }
            char t = stk[top];
            if (t == '(')
            {
                if (wr_idx == -1)
                {
                    cnt--;
                }
                top--;
            }
            else
            {
                if (wr_idx == -1)
                {
                    cnt++;
                }
                top--;
            }
        }
        if (wr_idx != -1 || cnt != 0)
        {
            err_flag = true;
        }
        else
        {
            err_flag = false;
        }
        if (err_flag)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}