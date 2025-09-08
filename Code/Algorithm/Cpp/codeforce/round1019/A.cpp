#include <iostream>
#include <bitset>
using namespace std;
const int N = 110;
bitset<N> vis;

void solve()
{
    vis.reset();
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (!vis[x])
        {
            cnt++;
            vis[x] = 1;
        }
    }
    cout << cnt << "\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}