#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 10;
vector<vector<int>> g(N, vector<int>());
bool flag = false;
int p;
void dfs(int u)
{
    for (auto &v : g[u])
    {
        if (flag)
        {
            return;
        }
        if (v == p)
        {
            cout << "Yes" << "\n";
            flag = true;
            return;
        }
        dfs(v);
    }
}

int main()
{
    int n;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        int u;
        cin >> u;
        g[u].push_back(i);
    }
    dfs(p);
    if (!flag)
    {
        cout << "No" << "\n";
    }
    return 0;
}