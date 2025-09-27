#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> prefix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    prefix[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    int cur_pos = 0;
    while (q--)
    {
        int op, c, l, r;
        cin >> op;
        if (op == 1)
        {
            cin >> c;
            cur_pos = (cur_pos + c) % n;
        }
        else
        {
            cin >> l >> r;
            l = (l - 1 + cur_pos + n) % n;
            r = (r - 1 + cur_pos + n) % n;
            ll sum = 0;
            if (l > r)
            {
                sum = prefix[n - 1] - (prefix[l - 1] - prefix[r]);
            }
            else if (l < r)
            {
                if (l != 0)
                {
                    sum = prefix[r] - prefix[l - 1];
                }
                else
                {
                    sum = prefix[r];
                }
            }
            else if (l == r)
            {
                sum = a[r];
            }
            cout << sum << "\n";
        }
    }
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}