#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 30;
ll arr[N];
int pos[N];
ll k, n, ans;

void dfs(int depth);

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        ans = 0;
        dfs(1);
        cout << ans << "\n";
    }
    return 0;
}

void dfs(int depth)
{
    if (depth > n)
    {
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += arr[i] * pos[i];
        }
        if (sum <= k)
        {
            ans++;
        }
        return;
    }
    // 选
    pos[depth] = 1;
    dfs(depth + 1);
    pos[depth] = 0;
    // 不选
    dfs(depth + 1);
}