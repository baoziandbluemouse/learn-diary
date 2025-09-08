#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
void solve()
{
    int n;
    cin >> n;
    vector<int> b(n + 1, 0);
    vector<int> cnt(n + 1, 0);
    map<int, vector<int>> list;
    vector<int> a(n + 1, 0);
    bitset<N> vis;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[b[i]]++;
        list[b[i]].push_back(i);
    }
    // int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        // int t = ((cnt[i] + i - 1) / i) * i;
        // sum += t;
        // if (sum > n)
        // {
        //     cout << -1 << "\n";
        //     return;
        // }
        if (cnt[i] % i != 0)
        {
            cout << -1 << "\n";
            return;
        }
    }
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        int temp = 0;
        int t = b[i];
        if (vis[t])
        {
            continue;
        }
        vis[t] = 1;
        for (int j = 0; j < list[t].size(); j++)
        {
            if (a[list[t][j]] == 0)
            {
                a[list[t][j]] = cur;
            }
            temp++;
            if (temp == t)
            {
                temp = 0;
                cur++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}