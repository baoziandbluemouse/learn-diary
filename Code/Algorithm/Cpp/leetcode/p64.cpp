#include <bits/stdc++.h>
using namespace std;
const int N = 220;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int dp[N][N];
        dp[0][0] = grid[0][0];
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 1; i < m; i++)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        // 边界
        // dp[i][j]代表到第[i,j]个格子时，所花费的最小权值
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                dp[i][j] = min(dp[i - 1][j] + grid[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << s.minPathSum(v) << "\n";
    return 0;
}
