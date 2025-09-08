#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    ll r;
    cin >> r;
    ll d = 11; // 10^k+1 ,k=1
    vector<ll> ans;
    while (r >= d)
    {
        if (r % d == 0)
        {
            ans.push_back(r / d);
        }
        d = (d - 1) * 10 + 1;
    }
    cout << ans.size() << "\n";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
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