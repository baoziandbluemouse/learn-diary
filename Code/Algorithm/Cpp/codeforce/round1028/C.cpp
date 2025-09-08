#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
int a[N];

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int g = a[1];
    for (int i = 2; i <= n; i++)
    {
        g = gcd(g, a[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == g)
        {
            cnt++;
        }
    }
    if (cnt)
    {
        cout << n - cnt << "\n";
        return;
    }
    vector<int> f(N, 1e9);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < N; j++)
        {
            int x = gcd(a[i], j);
            f[x] = min(f[x], f[j] + 1);
        }
        // 初始化,前i个数字，要使gcd为a[i]，只选一个数最好
        f[a[i]] = 1;
    }
    cout << f[g] - 2 + n << "\n";
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