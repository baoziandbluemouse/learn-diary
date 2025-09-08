#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 20;
ll a[N];
int n;
ll k;
ll ans;

void dfs(int dep, ll sum)
{
    if (sum >= k)
    {
        return;
    }
    else
    {
        ans = max(ans, sum);
    }
    if (dep == n + 1)
    {
        ans = max(ans, sum);
        return;
    }
    // 选
    dfs(dep + 1, sum + a[dep]);
    // 不选
    dfs(dep + 1, sum);
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}