#include <bits/stdc++.h>
using namespace std;
string s[2020];

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    for (i = 0; i < n; i++)
        cin >> s[i];
    vector<vector<int>> v;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j < m; j++)
        {
            if (s[i][j - 1] == '0')
            {
                s[i][j] = '1' - s[i][j] + '0';
                s[i][j - 1] = '1' - s[i][j - 1] + '0';
                v.push_back({i, j - 1, i, j});
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        if (s[i - 1][m - 1] == '0')
        {
            s[i][m - 1] = '1' - s[i][m - 1] + '0';
            s[i - 1][m - 1] = '1' - s[i - 1][m - 1] + '0';
            v.push_back({i, m - 1, i - 1, m - 1});
        }
    }
    if (s[n - 1][m - 1] == '0')
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << v.size() << "\n";
    for (auto i : v)
    {
        for (auto j : i)
        {
            cout << j + 1 << " ";
        }
        cout << "\n";
    }
    return 0;
}