#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 1; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            // n与n/i两个因子
            v.push_back(i);
            if (i != n / i)
            {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    for (auto &i : v)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}