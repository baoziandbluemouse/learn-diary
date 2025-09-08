#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], stk[N];
int n;
int l[N];
void solve1()
{
    // 栈中存优秀的用于当左边第一个最大数的数
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[i] >= a[stk[top]])
        {
            top--;
        }
        if (top > 0)
        {
            l[i] = a[stk[top]];
        }
        else
        {
            l[i] = -1;
        }
        stk[++top] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " ";
    }
    cout << "\n";
}
void solve2()
{
    // 栈中存还未找到右边第一个比它大的数的数
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[i] > a[stk[top]])
        {
            int j = stk[top];
            top--;
            l[j] = a[i];
        }
        stk[++top] = i;
    }
    while (top > 0)
    {
        int j = stk[top];
        top--;
        l[j] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " ";
    }
    cout << "\n";
}

void solve3()
{
    // 栈中存优秀的用于当左边第一个最小数的数
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[i] <= a[stk[top]])
        {
            top--;
        }
        if (top > 0)
        {
            l[i] = a[stk[top]];
        }
        else
        {
            l[i] = -1;
        }
        stk[++top] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " ";
    }
    cout << "\n";
}
void solve4()
{
    // 栈中存还未找到右边第一个比它小的数的数
    int top = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && a[i] < a[stk[top]])
        {
            int j = stk[top];
            top--;
            l[j] = a[i];
        }
        stk[++top] = i;
    }
    while (top > 0)
    {
        int j = stk[top];
        top--;
        l[j] = -1;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << l[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    solve1();
    solve2();
    solve3();
    solve4();
    return 0;
}