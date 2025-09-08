#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e3 + 9;

int pre[N];

int root(int x)
{
    if (pre[x] == x)
    {
        return x;
    }
    else
    {
        int root_x = root(pre[x]);
        pre[x] = root_x;
        return root_x;
    }
}

void merge(int u, int v)
{
    pre[root(u)] = root(v);
}

bool isCon(int u, int v)
{
    return root(u) == root(v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a, b);
    }
    for (int i = 1; i <= p; i++)
    {
        int u, v;
        cin >> u >> v;
        if (isCon(u, v))
        {
            cout << "Yes" << "\n";
        }
        else
        {
            cout << "No" << "\n";
        }
    }
    return 0;
}