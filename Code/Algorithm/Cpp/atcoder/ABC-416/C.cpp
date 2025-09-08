#include <bits/stdc++.h>
using namespace std;
const int N = 15;
string a[N];
vector<string> ans;
int n, k, x;

void dfs(int dep, string temp)
{
    if (dep == k + 1)
    {
        ans.push_back(temp);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(dep + 1, temp + a[i]);
    }
}

int main()
{
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1, "");
    sort(ans.begin(), ans.end());
    cout << ans[x - 1] << "\n";
    return 0;
}