#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;

int pos[N], id[N], g[N]; // pos[i]代表i号鸟在的巢穴，g[i]代表i号位置放的巢穴（一开始是一对一的）,id[i]代表i号巢穴所在的位置

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        pos[i] = i;
        id[i] = i;
        g[i] = i; // 一开始是一一对应的
    }
    while (q--)
    {
        int op, a, b;
        cin >> op;
        if (op == 1) // 改变鸟a的位置，放到位置b
        {
            cin >> a >> b;
            pos[a] = g[b]; // 巢穴b在g[b],所以鸟a的位置就要转移到g[b]
        }
        else if (op == 2)
        {
            cin >> a >> b; // 鸟巢a和鸟巢b互换 ,巢穴a的位置和巢穴b的位置互换
            // 那么就是a号巢穴在b号位置，b号巢穴在a号位置，id和g都要进行互换
            id[g[a]] = b;
            id[g[b]] = a;
            swap(g[a], g[b]);
        }
        else
        {
            cin >> a; // 查询鸟a在哪个巢穴
            cout << id[pos[a]] << "\n";
        }
    }
    return 0;
}