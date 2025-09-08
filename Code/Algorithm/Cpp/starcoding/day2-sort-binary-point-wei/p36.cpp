#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
typedef long long ll;
int arr[N], c[N];
void solve(void)
{
    int n;
    ll maxx = -1;
    cin >> n;
    memset(arr, 0, sizeof(int) * n + 1); // 初始化数组
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        c[arr[i]] = 0; // 初始化桶
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j < n && !c[arr[j + 1]])
        {
            j++;
            c[arr[j]]++;
        }
        maxx = max(maxx, j - i + 1ll);
        c[arr[i]]--;
    }
    cout << maxx << '\n';
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
