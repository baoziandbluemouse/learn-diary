#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int N = 2e5 + 10;
int vis[N];
int bfs(int n, int k)
{
    queue<int> q;
    memset(vis, -1, sizeof(vis));
    vis[n] = 0;
    q.push(n);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        if (t == k)
            return vis[t];
        if (t - 1 >= 0 && vis[t - 1] == -1)
        {
            q.push(t - 1);
            vis[t - 1] = vis[t] + 1;
        }
        if (t + 1 <= N && vis[t + 1] == -1)
        {
            q.push(t + 1);
            vis[t + 1] = vis[t] + 1;
        }
        if (t * 2 <= N && vis[t * 2] == -1)
        {
            q.push(t * 2);
            vis[t * 2] = vis[t] + 1;
        }
    }
    return -1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int ans = bfs(n, k);
    cout << ans << "\n";
    return 0;
}