#include <iostream>
using namespace std;
using ll = long long;
const ll mod = 1e9;
const int N = 1e6 + 10;
ll a[N];
int main()
{
    ll n, k;
    cin >> n >> k;
    if (n < k)
    {
        cout << 1 << "\n";
        return 0;
    }
    for (ll i = 0; i < k; i++)
        a[i] = 1;
    ll cur = k;
    for (ll i = k; i <= n; i++)
    {
        a[i] = cur;
        cur -= a[i - k];
        cur += a[i];
        cur = (cur + mod) % mod; // 加上mod防止负数
    }
    cout << a[n] << "\n";
    return 0;
}