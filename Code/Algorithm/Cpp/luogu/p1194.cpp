#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int pre[N];
struct node
{
    int u, v, w;
    bool operator<(const node &b) const
    {
        if (w != b.w)
        {
            return w < b.w;
        }
        else if (u != b.u)
        {
            return u < b.u;
        }
        return v < b.v;
    }
};

vector<node> e;

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

void merge(int x, int y)
{
    pre[root(x)] = root(y);
}

bool isCon(int x, int y)
{
    return root(x) == root(y);
}

void build(int u, int v, int w)
{
    e.push_back({u, v, w});
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        pre[i] = i;
    }
    for (int i = 1; i <= b; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            int w;
            cin >> w;
            if (w != 0 && w <= a)
            {
                build(i, j, w);
            }
        }
    }
    sort(e.begin(), e.end());
    int ans = 0;
    if (a == 0)
    {
        cout << 0 << "\n";
        return 0;
    }
    int cnt = 0;
    for (auto &i : e)
    {
        int u = i.u;
        int v = i.v;
        int w = i.w;
        if (isCon(u, v))
        {
            continue;
        }
        merge(u, v);
        ans += w;
        cnt++;
    }
    if (cnt == b - 1)
    {
        cout << ans + a << "\n";
    }
    else
    {
        cout << ans + a * (b - cnt) << "\n";
    }

    return 0;
}