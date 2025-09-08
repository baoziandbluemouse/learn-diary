#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>());
    vector<vector<int>> b(m + 1, vector<int>());
    vector<bool> ux(n + 1);
    vector<bool> uy(m + 1);
    vector<bool> use(k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(i);
        b[y].push_back(i);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int x;
            cin >> x;
            if (ux[x])
            {
                cout << "0\n";
            }
            else
            {
                int ans = 0;
                ux[x] = 1;
                for (auto &e : a[x])
                {
                    if (!use[e])
                    {
                        use[e] = 1;
                        ans++;
                    }
                }
                cout << ans << "\n";
            }
        }
        else if (opt == 2)
        {
            int y;
            cin >> y;
            if (uy[y])
            {
                cout << "0\n";
            }
            else
            {
                int ans = 0;
                uy[y] = 1;
                for (auto &e : b[y])
                {
                    if (!use[e])
                    {
                        use[e] = 1;
                        ans++;
                    }
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}