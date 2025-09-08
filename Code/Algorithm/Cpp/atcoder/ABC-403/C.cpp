#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
bitset<N> vis;
struct node
{
    map<int, int> mp;
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<node> a(n + 1);
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y;
            cin >> x >> y;
            a[x].mp[y] = 1;
        }
        else if (op == 2)
        {
            int x;
            cin >> x;
            vis[x] = 1;
        }
        else if (op == 3)
        {
            int x, y;
            cin >> x >> y;
            if (vis[x])
            {
                cout << "Yes\n";
                continue;
            }
            if (a[x].mp.count(y))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }
    return 0;
}