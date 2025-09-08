#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int q;
    cin >> q;
    queue<pair<ll, ll>> dq;
    while (q--)
    {
        ll op, c, x, k;
        cin >> op;
        if (op == 1)
        {
            cin >> c >> x;
            dq.push({c, x});
        }
        else
        {
            cin >> k;
            ll sum = 0;
            while (k > 0)
            {
                auto t = dq.front();
                ll cnt = t.first;
                ll val = t.second;
                if (cnt <= k)
                {
                    sum += 1ll * cnt * val;
                    dq.pop();
                    k -= cnt;
                }
                else
                {
                    sum += 1ll * k * val;
                    dq.front().first -= k;
                    k = 0;
                }
            }
            cout << sum << "\n";
        }
    }
    return 0;
}