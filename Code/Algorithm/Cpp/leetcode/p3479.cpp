#include <bits/stdc++.h>
using namespace std;

class Segmentree
{
    vector<int> mx;
    void maintain(int o) { mx[o] = max(mx[o * 2], mx[o * 2 + 1]); }
    void build(const vector<int> &a, int o, int l, int r)
    {
        if (l == r)
        {
            mx[o] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, o * 2, l, m);
        build(a, o * 2 + 1, m + 1, r);
        maintain(o);
    }

public:
    Segmentree(const vector<int> &a)
    {
        size_t n = a.size();
        mx.resize(n * 4);
        build(a, 1, 0, n - 1);
    }
    int queryandupdate(int o, int l, int r, int x)
    {
        if (mx[o] < x)
        {
            return -1;
        }
        if (l == r)
        {
            mx[o] = -1;
            return l;
        }
        int m = (l + r) / 2;
        int i = queryandupdate(o * 2, l, m, x); // 优先查询左子树
        if (i == -1)
        {
            // 如果左子树没有找到符合条件的节点，则查询右子树
            i = queryandupdate(o * 2 + 1, m + 1, r, x);
        }
        maintain(o); // 维护节点的最大值,进行更新
        return i;
    }
};

class Solution
{
public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        Segmentree t(baskets);
        int n = baskets.size(), ans = 0;
        for (int x : fruits)
        {
            if (t.queryandupdate(1, 0, n - 1, x) < 0)
            {
                ans++;
            }
        }
        return ans;
    }
};
