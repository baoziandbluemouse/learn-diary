#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    vector<array<int, 2>> ans;
    int x = 0, y = 0;
    for (int i = 450; i >= 2; i--)
    {
        int cnt = i * (i - 1) / 2;
        while (k - cnt >= 0)
        {
            k -= cnt;
            for (int j = 0; j < i; j++)
            {
                ans.push_back({x, y + j});
            }
            x++;
            y += i + 1;
        }
    }
    cout << ans.size() << "\n";
    for (auto &e : ans)
    {
        int a = e[0];
        int b = e[1];
        cout << a << " " << b << "\n";
    }
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