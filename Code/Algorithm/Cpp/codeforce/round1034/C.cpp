#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    vector<int> l(n + 1, 0);
    vector<int> r(n + 1, 0);
    stack<int> stk;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--)
    {
        while (stk.size() && a[stk.top()] >= a[i])
        {
            l[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    while (stk.size())
    {
        stk.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && a[stk.top()] <= a[i])
        {
            r[stk.top()] = a[i];
            stk.pop();
        }
        stk.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == 0 || r[i] == 0)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
    cout << "\n";
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