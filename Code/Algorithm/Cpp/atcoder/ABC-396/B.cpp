#include <bits/stdc++.h>
using namespace std;
const int N = 300;
int stk[N], top;

void solve()
{
    int opt, x;
    cin >> opt;
    if (opt == 1)
    {
        int x;
        cin >> x;
        stk[++top] = x;
    }
    else
    {
        cout << stk[top--] << "\n";
    }
}

int main()
{
    int q;
    cin >> q;
    top = 100;
    while (q--)
    {
        solve();
    }
    return 0;
}