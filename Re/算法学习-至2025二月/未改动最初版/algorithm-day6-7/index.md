---
title: 图的存储，并查集，最短路
description: 请输入文字描述
date: 2025-01-23
image: ok.jpg
categories:
    - Algorithm
    - 图的存储
    - 并查集
    - 最短路
---

# 前言

**学习网站**:[Starrycoding](https://www.starrycoding.com/)

**有关图的基本概念**:[oi wiki](https://oi-wiki.org//graph/save/)


## 图的存储

在题目中，想要对图进行操作，就需要将图存储下来。

常见的图的存储方式有：
- 邻接矩阵
- 邻接表


### 邻接矩阵

邻接矩阵是一种用二维数组来表示图的方式。

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/linjiejuzhen.png)

使用一个二维数组$a$来表示图，其中$a[i][j]$值为1表示存在从点$i$到点$j$的边，值为0表示不存在。如果是带有权值的图，那么$a[i][j]$值为权值。

### 邻接表

邻接表的实现方式有两种，一种是链式前向星，另一种通过vector数组。

我们这里介绍用vector数组实现的，这种方法也更方便排序。

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/linjiebiao.png)

使用一个vector数组$a$来表示图，其中$a[i]$表示从**点$i$出发的所有边**。显而易见这是个**二维数组**。

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/linjiebiao2.png)

```cpp
vector<vector<int>> g(N, vector<int>()); // graph
```

假设我们要添加一条从点$u$到点$v$的边，那么我们可以这样：
```cpp
g[u].push_back(v);
```
假如还有一条从点$u$到点$w$的边，就再push_back一次即可.



#### 例题

[P42 树的遍历](https://www.starrycoding.com/problem/42)

分析：

存储树，我们可以用一个数组来存储每个点的**父节点**。

然后再用邻接表来存储树。只需要把父节点作为起点，子节点作为终点，添加一条边即可。最后就可以对树进行遍历了。注意此处要从小到大输出，所以我们可以对邻接表进行排序

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 60;
int fa[N];
vector<vector<int>> g(N, vector<int>()); // graph

void dfs(int x)
{
    cout << x << " ";
    for (auto &y : g[x])
    {
        dfs(y);
    }
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";
        for (auto &y : g[x])
            q.push(y);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
    }
    for (int i = 2; i <= n; i++)
    {
        g[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(g[i].begin(), g[i].end());
    }
    dfs(1);
    cout << "\n";
    bfs(1);
    return 0;
}
```


[P64 图的遍历](https://www.starrycoding.com/problem/64)

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

bitset<N> vis;
vector<vector<int>> g(N, vector<int>());

void dfs(int x)
{
    vis[x] = true;
    for (auto &y : g[x])
    {
        if (vis[y])
            continue;
        dfs(y);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            cout << i << " ";
    }
    cout << "\n";
    return 0;
}
```


## 并查集


![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/bingchaji1.png)

并查集，并指**合并**，查指**查询（联通关系）**，集指**集合**。

并查集可以用来做联通块的问题。**并查集的所有操作都是对根节点进行的**。

并查集的具体操作有：
1. 初始化：一个数组$pre$, 假设有点$u$和$v$，在一开始我们初始化认为这两个点是**自环的**，即$pre[u] = u, pre[v] = v$.因此初始化为$pre[i] = i$
2. root函数：通过这个函数找到一个点的根节点。**最重要的函数**.
3. 合并：将两个点联通，实际就是将**两个点的根节点合并**。即$pre[root(u)] = root(v)$
4. 查询：查询两个点是否联通，即$root(u) == root(v)$



![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/bingchaji2.png)


朴素版root函数:
```cpp
int root(int x)
{
    if (pre[x] == x)
        return x;
    else
        return root(pre[x]);  // 递归找到根节点
}
```

朴素版的时间复杂度为$O(n)$，但是我们往往会查询很多点的root，这样的时间复杂度就会很高。因此我们需要优化root函数。

路径压缩版root函数：


![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/bingchaji3.png)

我们在一次找到根节点后，其实就能将**整条路径上的所有点的根节点都更新为根节点**。这样就可以大大减少时间复杂度。我们只需要进行极少次的$O(n)$操作，后续都能是$O(1)$的。均摊下来时间复杂度就很小了。

```cpp
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
```

### 例题

[P68 联通块问题](https://www.starrycoding.com/problem/68)

```cpp
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
```

## 最短路

普通的无权图的最短路问题，一般用**BFS**来解决。

但是当我们遇到**有权图**的最短路问题时，就需要使用**最短路算法**来解决。

常见的最短路算法有：
- Dijkstra（处理**单源**最短路）
- Floyd(处理**多源**最短路)


### Dijkstra

Dijkstra算法是一种贪心算法，它的思想是：**每次都选择当前距离起点最近的点，然后更新它的邻居的距离**。

Dijkstra算法的步骤：

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/dijkstra.png)

1. 初始化一个数组$dis$，$dis[i]$表示从起点到点$i$的最短距离。初始化$dis[起点] = 0$，其他点的距离都为$inf$.

2. 初始化一个数组$vis$，$vis[i]$表示点$i$是否已经找到最短路径。如果已经找到了最短路径，那么$vis[i] = true$，这个点不需要再更新了。开始时就是$vis[起点] = true$


![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/dijkstra2.png)

1. 松弛操作：我们从起点开始，每次选择当前距离起点最近的点，然后更新它的邻居的距离。即$dis[邻居] = min(dis[邻居], dis[当前点] + 边权)$.

2. 如图我们更新完二号和三号点后，一号的邻居点都已经更新完毕，接下来我们就要在这些邻居点中找到$d[i]$最小的点，这个点就是**下一个起点**，根据性质，这个点的$d[i]$一定是最小的。那么这个点的$vis[i]$就可以置为$true$了。如图，我们选择**二号点**作为起点继续更新。

3. 重复上述操作，直到所有点都找到最短路径。

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/dijkstra3.png)


![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/dijkstra4.png)


#### 例题1

[P69 【模板】最短路（1）](https://www.starrycoding.com/problem/69)

这一题就是Dijkstra算法的模板题。但是是朴素版，时间复杂度是$O(n^2)$。

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 9;
typedef long long ll;

struct node
{
    int x, w; // x表示出点，w表示权值
};
vector<vector<node>> g(N, vector<node>());
ll d[N], n, m;

void dijkstra(int st)
{
    memset(d, 0x3f, sizeof(ll) * (n + 1));
    d[st] = 0;
    bitset<N> vis; // 记录已经被拓展过的
    for (int i = 1; i <= n - 1; i++)
    {
        // 找出最小点（距离源点最近的点）
        int u = 1;
        for (int j = 1; j <= n; j++)
        {
            if (vis[u] || (!vis[j] && d[j] < d[u]))
            {
                u = j;
            }
        }

        // 表示u已被拓展
        vis[u] = true;

        // 此时d[u]已为最优的，别的不一定
        for (const auto &edge : g[u])
        {
            int v = edge.x;
            int w = edge.w;
            if (!vis[v] && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) // 避免自环
        {
            g[u].push_back({v, w});
        }
    }

    dijkstra(1);

    cout << (d[n] >= 0x3f3f3f3f ? -1 : d[n]) << "\n"; // 输出d[n]，若d[n]未被更新，则输出-1(即d[n]>=0x3f3f3f3f)

    return 0;
}
```


#### 例题2

[P70 【模板】最短路（2）](https://www.starrycoding.com/problem/70)

上一题虽然我们实现了，但是时间复杂度实在难以接受，我们可以考虑使用**堆优化**的Dijkstra算法。(使用优先队列)时间复杂度为$O(m\log m)$。

```cpp
for (int i = 1; i <= n - 1; i++)
    {
        // 找出最小点（距离源点最近的点）
        int u = 1;
        for (int j = 1; j <= n; j++)
        {
            if (vis[u] || (!vis[j] && d[j] < d[u]))
            {
                u = j;
            }
        }

        // 表示u已被拓展
        vis[u] = true;

        // 此时d[u]已为最优的，别的不一定
        for (const auto &edge : g[u])
        {
            int v = edge.x;
            int w = edge.w;
            if (!vis[v] && d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
            }
        }
    }
```
观察这个循环，我们可以发现，每次都要找到$d[i]$最小的点，这个过程是$O(n)$的。我们可以使用**优先队列**来优化这个过程。

```cpp
void dijkstra(int st)
{
    memset(d, 0x3f, sizeof(ll) * (n + 1));
    d[st] = 0;
    bitset<N> vis;           // 记录已经被拓展过的
    priority_queue<node> pq; // 进入队列的点，按权值从小到大排序
    pq.push({st, d[st]});    // 将源点加入优先队列
    while (pq.size())
    {
        int u = pq.top().x;
        pq.pop();
        if (vis[u]) // 跳过冗余点
            continue;
        vis[u] = true; // 标记u已得到最短距离，不再更新
        for (const auto &edge : g[u])
        {
            int v = edge.x;
            int w = edge.w;
            if (!vis[v] && d[v] > d[u] + w) // 如果vis[v]为true，则该点已得到最短路径，无需更新
            {
                d[v] = d[u] + w;
                pq.push({v, d[v]});
            }
        }
    }
}
```

还要注意的是，我们使用优先队列时，需要**重载**小于(<)号。

```cpp
struct node
{
    ll x, w; // x表示出点，w表示权值
    bool operator<(const node &v) const
    {
        return w == v.w ? (x < v.x) : (w > v.w); // 重载<运算符，(优先比较权值）w从小到大排序,若权值相等，则按x排序
        // 注意优先队列的比较器是相反的，要小根堆，就得是w>v.w,和sort函数之类的比较器写法相反
    }
};
```

可以看出，使用优先队列优化的Dijkstra算法和bfs是有点像的。


### Floyd

Floyd算法是一种**多源**最短路算法，它的思想是：**枚举中间点**，然后更新所有点之间的距离。

由于Floyd的高复杂度$O(n^3)$，所以数据范围一定会在$300$左右。

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/floyd.png)

Floyd的模板就是一个三重循环。

```cpp
for (int k = 1; k <= n; k++) //注意这个中间点必须放在第一层循环
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
}
```

![](算法学习-至2025二月/未改动最初版/algorithm-day6-7/floyd2.png)

Floyd是一个很宏观的算法，它不会理会具体的路径，只是枚举所有的路径。然后找出最短的路径。


#### 例题

[P71 【模板】最短路（3）](https://www.starrycoding.com/problem/71)

```cpp
#include <bits/stdc++.h>
using namespace std;
const int N = 350;
typedef long long ll;
const ll inf = 0x3f3f3f3f;

ll d[N][N], n, m, q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    memset(d, 0x3f, sizeof(d));
    for (int i = 1; i <= m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w); // 存储最小的边权
    }

    // 初始化
    for (int i = 1; i <= n; i++)
    {
        d[i][i] = 0; // 自环为0
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << (d[u][v] >= inf ? -1 : d[u][v]);
    }

    return 0;
}
```