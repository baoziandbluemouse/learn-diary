#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 1;
bitset<N> vis;
vector<int> prime;
int m;
void init()
{
    vis[0] = vis[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (int j = i * 2; j < N; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    reverse(prime.begin(), prime.end());
    m = prime.size();
}

void solve()
{
    int n;
    cin >> n;
    ll ans = 0;
    int l = 0;
    for (int i = 1; i <= n; i++)
    {
        while (l < m && prime[l] * i > n)
            l++;
        ans += m - l;
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    init();
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
}