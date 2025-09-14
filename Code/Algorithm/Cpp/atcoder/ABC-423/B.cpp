#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 2)
    {
        if (a[1] == 0 || a[2] == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
        return;
    }
    int fir = 0, end = n;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            fir = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 1)
        {
            end = i;
            break;
        }
    }
    int cnt = end - fir;
    cout << cnt << "\n";
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