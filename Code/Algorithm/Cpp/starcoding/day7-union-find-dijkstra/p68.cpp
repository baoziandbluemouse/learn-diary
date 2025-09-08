#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;

int pre[N], cnt[N];

int root(int x) // 路径压缩实现寻找根节点，并将沿途的节点都指向根节点
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

void merge(int x, int y) // 这里x和y的顺序是无所谓的,都正确
{
    pre[root(x)] = root(y);
}

bool isCon(int x, int y) // 判断x和y是否连通
{
    return root(x) == root(y);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = i;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        merge(u, v);
    }
    for (int i = 1; i <= n; i++) // 使用一个桶来统计每个连通块的大小
    {
        cnt[root(i)]++;
    }
    vector<int> v; // 用vector方便排序
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i])
        {
            v.push_back(cnt[i]);
        }
    }
    sort(v.begin(), v.end());
    for (auto &y : v)
    {
        cout << y << " ";
    }
    cout << "\n";
    return 0;
}