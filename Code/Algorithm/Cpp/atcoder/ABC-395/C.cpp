#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (a[x]) // 如果x之前出现过
        {
            ans = min(ans, i - a[x] + 1);
        }
        a[x] = i;
    }
    if (ans == 1e9)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << ans << "\n";
    }
    return 0;
}