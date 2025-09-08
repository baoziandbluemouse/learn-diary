#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;
const int N = 1100;
int g[N][N];
bitset<N> st[N];
int bfs(int x1, int y1);
ll n, m, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
        {
            st[i].reset();
            for (int j = 1; j <= m; j++)
            {
                cin >> g[i][j];
            }
        }
        vector<int> s;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (g[i][j] == 0 && !st[i][j])
                {
                    int cnt = bfs(i, j);
                    if (cnt >= k)
                    {
                        s.push_back(cnt);
                    }
                }
            }
        }
        if (s.size())
        {
            sort(s.begin(), s.end());
            for (auto x : s)
            {
                cout << x << " ";
            }
        }
        else
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}

int bfs(int x1, int y1)
{
    queue<PII> q;
    q.push({x1, y1});
    int res = 0;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        if (st[t.first][t.second])
        {
            continue;
        }
        st[t.first][t.second] = true;
        res++;
        for (int i = 0; i < 4; i++)
        {
            int a = t.first + dx[i];
            int b = t.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
            {
                continue;
            }
            if (g[a][b] == 1)
            {
                continue;
            }
            q.push({a, b});
        }
    }
    return res;
}