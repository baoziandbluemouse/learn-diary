#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], fa[N];
string s[N];

void dfs(int x)
{
    if (!x)
        // 0结点返回
        return;
    dfs(fa[x]);
    cout << s[x];
}
/*
    维护一个图，用边来表示操作
    a[x] -> 第x个字符串，对应哪个点
    fa[num] -> 第num个点，是由哪个点转移过来的(父节点)
    s[num] -> 从 fa[num] 到 num  新增了哪个字符串
    nw -> 根节点实际上是哪个点
*/
int main()
{
    int n, q, num = 0, nw = 0;
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
            a[x] = nw; // 直接让a[x]指向服务器所在的点
        else if (op == 2)
        { // 新增一条边，从a[x] -> num， 新增的字符串是s[num]
            num++;
            cin >> s[num];
            fa[num] = a[x];
            a[x] = num;
        }
        else
            nw = a[x];
        // 让服务器指向a[x]所在的点
    }
    dfs(nw);
    return 0;
}