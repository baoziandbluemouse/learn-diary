#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>> vis(n + 10, vector<int>(m + 10, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                {
                    res = bfs(i, j, vis, grid, n, m);
                    break;
                }
            }
            break;
        }
        return res;
    }

    int bfs(int stx, int sty, vector<vector<int>> &vis,
            vector<vector<int>> &grid, int n, int m)
    {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.push({stx, sty});
        vis[stx][sty] = 1;
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int a = t.first + dx[i];
                int b = t.second + dy[i];
                if (a < 0 || a >= n || b < 0 || b >= m)
                {
                    cnt++;
                    continue;
                }
                if (grid[a][b] == 0)
                {
                    cnt++;
                    continue;
                }
                if (vis[a][b] == 1)
                {
                    continue;
                }
                q.push({a, b});
                vis[a][b] = 1;
            }
        }
        return cnt;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    Solution obj;
    int ans = obj.islandPerimeter(grid);
    cout << ans << endl;
    return 0;
}