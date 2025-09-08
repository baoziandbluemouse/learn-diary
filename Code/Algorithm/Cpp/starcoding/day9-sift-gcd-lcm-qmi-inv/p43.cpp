#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 9;
bitset<N> vis;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vis[0] = true;
    vis[1] = true;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                vis[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}