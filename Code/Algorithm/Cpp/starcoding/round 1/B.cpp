#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int a, n;
    cin >> a >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            if (p[i] - j <= 0)
            {
                break;
            }
            int x = p[i] - j;
            if ((a - j) % 2 == 0 && (a - j) / 2 == x)
            {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}