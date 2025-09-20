#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int vis[N][N];
int outvis[N];
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int cnt = 1;
    vector<int> out;

    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        vis[a][b] = 1;
        bool flag = false;
        for (int j = 1; j <= m; j++)
        {
            if (vis[a][j] == 0)
            {
                flag = true;
            }
        }
        if (!flag && outvis[a] == 0)
        {
            out.push_back(a);
            outvis[a] = 1;
        }
    }
    for (auto &x : out)
    {
        cout << x << " ";
    }
    cout << "\n";
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