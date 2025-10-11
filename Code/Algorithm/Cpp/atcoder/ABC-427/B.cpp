#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int f[N];

int change(int x)
{
    int ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    f[0] = 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += change(f[i - 1]);
        f[i] = sum;
    }
    cout << f[n] << "\n";
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