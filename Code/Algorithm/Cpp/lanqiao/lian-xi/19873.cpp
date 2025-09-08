#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int pre[N], num[N];

int root(int x)
{
    if (pre[x] == x)
        return x;
    int t = root(pre[x]);

    pre[x] = t;
    return t;
}

void merge(int x, int y)
{
    int rx = root(x), ry = root(y);
    if (rx != ry)
    {
        pre[rx] = ry;
        num[ry] += num[rx];
    }
}

bool isCon(int x, int y)
{
    return root(x) == root(y);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
        num[i] = 1;
    }
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "C")
        {
            int u, v;
            cin >> u >> v;
            merge(u, v);
        }
        else if (op == "Q1")
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
        else if (op == "Q2")
        {
            int u;
            cin >> u;
            cout << num[root(u)] << "\n";
        }
    }
    return 0;
}