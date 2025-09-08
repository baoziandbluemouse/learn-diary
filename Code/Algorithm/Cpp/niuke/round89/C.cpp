#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll qmi(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    ll res = qmi(2, n - k + 1);
    cout << res << "\n";
    return 0;
}