#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 9;
struct node
{
    int left;
    int right;
} a[N];

ll ans = 0;

void dfs(int x, ll dep) // x是当前节点，dep是深度
{
    if (x == 0) // 假如a[x]下面没有了，再进行深搜x就会变为0
        return;
    ans = max(ans, dep);
    dfs(a[x].left, dep + 1); // 左儿子
    dfs(a[x].right, dep + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].left >> a[i].right;
    }
    dfs(1, 1);
    cout << ans << "\n";
    return 0;
}