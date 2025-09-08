#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 110;
struct node
{
    char c;
    ll val;
};
node a[N];
void solve()
{
    int n;
    ll len = 0;
    bool flag = false;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].c >> a[i].val;
        if (len <= 100)
        {
            len += a[i].val;
        }
        if (len > 100)
        {
            flag = true;
        }
    }
    if (flag)
    {
        cout << "Too Long\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            char p = a[i].c;
            ll cnt = a[i].val;
            for (int j = 1; j <= cnt; j++)
            {
                cout << p;
            }
        }
        cout << "\n";
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