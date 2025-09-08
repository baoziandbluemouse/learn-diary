#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        if (x == 0)
        {
            sum++;
        }
    }
    cout << sum << "\n";
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