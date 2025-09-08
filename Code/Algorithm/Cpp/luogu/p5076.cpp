#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e4 + 9;
const ll inf = 2147483647;
struct node
{
    int val;   // 权值
    int left;  // 左子树下标
    int right; // 右子树下标
    int cnt;   // 该节点权值出现次数
    int siz;   // 子树大小和自己大小的和
} tree[N];

int p, opt, x, cont;

void add(int pos, int v) // pos 代表当前节点下标，v代表要插入的权值
{
    tree[pos].siz++;
    // 如果查到这个节点，那么他的子树一定会有一个节点要插入v，所以siz++
    if (tree[pos].val == v)
    {
        tree[pos].cnt++;
        return;
    }
    if (v < tree[pos].val)
    {
        if (tree[pos].left != 0) // 当前节点的左子树不为空，继续递归寻找
        {
            add(tree[pos].left, v);
        }
        else
        {
            cont++;
            tree[cont].val = v;
            tree[cont].cnt = 1;
            tree[cont].siz = 1;
            tree[pos].left = cont; // 插入空的左子树
        }
    }
    else
    {
        if (tree[pos].right != 0)
        {
            add(tree[pos].right, v);
        }
        else
        {
            cont++;
            tree[cont].val = v;
            tree[cont].cnt = 1;
            tree[cont].siz = 1;
            tree[pos].right = cont; // 插入空的右子树
        }
    }
}

int get_fr(int pos, int v, int ans) // 求v的前驱
{
    if (tree[pos].val >= v) // 说明当前节点大了,要往左子树走
    {
        if (tree[pos].left == 0) // 左子树为空，说明没有比v小的数了，返回上一个答案(或是返回-inf)
        {
            return ans;
        }
        else
        {
            return get_fr(tree[pos].left, v, ans);
        }
    }
    else // 当前节点比v小，那么v的前驱可能是当前节点，也可能是当前节点的右子树
    {
        // 先判断右子树是否为空
        if (tree[pos].right == 0)
        {
            return (tree[pos].val > ans) ? tree[pos].val : ans; // 判断一下当前节点好还是上一个找到的ans好，一般来说都是当前节点
        }

        // 右子树不为空，那么我们就要递归右子树，当前节点可能是答案,在下次递归时能判断出来
        // if (tree[pos].cnt != 0)
        // {
        //     return get_fr(tree[pos].right, v, tree[pos].val);
        // }
        // else
        // {
        //     return get_fr(tree[pos].right, v, ans);
        // }
        return get_fr(tree[pos].right, v, tree[pos].val);
    }
}

int get_la(int pos, int v, int ans) // 求v的后继
{
    if (tree[pos].val <= v) // 说明当前节点小了,要往右子树走
    {
        if (tree[pos].right == 0) // 右子树为空，说明没有比v大的数了，返回上一个答案(或是返回inf)
        {
            return ans;
        }
        else
        {
            return get_la(tree[pos].right, v, ans);
        }
    }
    else // 当前节点比v大，那么v的后继可能是当前节点，也可能是当前节点的左子树
    {
        // 先判断左子树是否为空
        if (tree[pos].left == 0)
        {
            return (tree[pos].val < ans) ? tree[pos].val : ans;
        }

        // if (tree[pos].cnt != 0)
        // {
        //     return get_la(tree[pos].left, v, tree[pos].val);
        // }
        // else
        // {
        //     return get_la(tree[pos].left, v, ans);
        // }
        return get_la(tree[pos].left, v, tree[pos].val);
    }
}

int get_rank(int pos, int v)
{
    if (pos == 0) // x不在集合，没找到
    {
        return 0;
    }
    if (v == tree[pos].val) // 找到了，返回左子树的大小
    {
        return tree[tree[pos].left].siz; // 返回的是排名-1，记得要把1加上
    }
    if (v < tree[pos].val) // 比当前节点小，去左子树找
    {
        return get_rank(tree[pos].left, v);
    }
    else
    {
        return get_rank(tree[pos].right, v) + tree[tree[pos].left].siz + tree[pos].cnt; // 去右子树找，还要加上左子树的大小和当前节点的值出现次数
    }
}

int get_num(int pos, int rank) // 找到排名为rank的数
{
    if (pos == 0)
    {
        return inf;
    }
    if (rank <= tree[tree[pos].left].siz) // 排名小于等于左子树的大小，去左子树找
    {
        return get_num(tree[pos].left, rank);
    }
    if (tree[tree[pos].left].siz + tree[pos].cnt >= rank) // 排名大于左子树的大小和当前节点的值出现次数，返回当前节点的值
    {
        return tree[pos].val;
    }

    // 去查右子树
    return get_num(tree[pos].right, rank - tree[tree[pos].left].siz - tree[pos].cnt);
    // 要减去左子树的大小和当前节点的值出现次数
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> p;
    while (p--)
    {
        cin >> opt >> x;
        if (opt == 1)
        {
            cout << get_rank(1, x) + 1 << '\n';
        }
        else if (opt == 2)
        {
            cout << get_num(1, x) << '\n';
        }
        else if (opt == 3)
        {
            cout << get_fr(1, x, -inf) << "\n";
        }
        else if (opt == 4)
        {
            cout << get_la(1, x, inf) << "\n";
        }
        else
        {
            if (cont == 0)
            {
                cont++;
                tree[cont].val = x;
                tree[cont].cnt = 1;
                tree[cont].siz = 1;
            }
            else
            {
                add(1, x);
            }
        }
    }
    return 0;
}