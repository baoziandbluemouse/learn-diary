#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b[i]--;
    }
    vector<array<int, 2>> res;
    auto move = [&](int t, int x) -> void
    {
        res.push_back({t, x});
        if (t == 3)
        {
            swap(a[x], b[x]);
        }
        else if (t == 1)
        {
            swap(a[x], a[x + 1]);
        }
        else
        {
            swap(b[x], b[x + 1]);
        }
    };
    for (int cur = 0; cur < 2 * n; cur++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == cur)
            {
                if (cur % 2 == 0)
                {
                    for (int j = i - 1; j >= cur / 2; j--)
                    {
                        move(1, j);
                    }
                }
                else
                {
                    move(3, i);
                    for (int j = i - 1; j >= cur / 2; j--)
                    {
                        move(2, j);
                    }
                }
                break;
            }
            else if (b[i] == cur)
            {
                if (cur % 2 == 0)
                {
                    move(3, i);
                    for (int j = i - 1; j >= cur / 2; j--)
                        move(1, j);
                }
                else
                {
                    for (int j = i - 1; j >= cur / 2; j--)
                        move(2, j);
                }
                break;
            }
        }
    }
    cout << res.size() << "\n";
    for (auto [x, y] : res)
        cout << x << " " << y + 1 << "\n";
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