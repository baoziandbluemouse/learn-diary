#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int l = 0, r = 4e5 + 10;
        while (l + 1 < r)
        {
            int mid = (l + r) / 2;
            if (check(mid, dungeon))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return r;
    }

    bool check(int mid, vector<vector<int>> &dungeon)
    {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> f(n, vector<int>(m, 0));
        f[0][0] = mid + dungeon[0][0];
        for (int i = 1; i < n; i++)
        {
            f[i][0] = f[i - 1][0] + dungeon[i][0];
        }
        for (int i = 1; i < m; i++)
        {
            f[0][i] = f[0][i - 1] + dungeon[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]) + dungeon[i][j];
            }
        }
        return f[n - 1][m - 1] >= 1;
    }
};

int main()
{
    Solution solution;
    int dugeon[3][3] = { {-2, -3, 3},
                         {-5, -10, 1},
                         {} }
}