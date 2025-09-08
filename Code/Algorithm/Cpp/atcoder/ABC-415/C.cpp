#include <bits/stdc++.h>
using namespace std;
const int N = 25;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    queue<int> q;
    vector<int> vis(1 << n, 0);
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        if (u == (1 << n) - 1)
        {
            // 已经到达了最大的状态，全部混合了
            cout << "Yes\n";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            // 选一个药，放进状态里
            if (u >> i & 1)
                continue;
            // 如果该药已经在状态里了，就不放进去了
            int v = u | (1 << i); // 算出新状态
            if (s[v] == '1' || vis[v])
                continue;
            // 如果已经标记，或者这个状态是危险的，就跳过了
            q.push(v);
            vis[v] = 1;
        }
    }
    // 最终要是都没有yes，那就no了
    cout << "No\n";
}
int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}