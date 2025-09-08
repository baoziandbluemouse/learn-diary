#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    // a= x-y
    // b= x^2+xy+y^2
    for (ll a = 1; a * a * a <= n; a++)
    {
        if (n % a != 0)
            continue;
        ll b = n / a;
        if (b > a * a && (b - a * a) % 3 == 0)
        {
            ll c = (b - a * a) / 3;
            // 求根公式
            ll d = a * a + 4 * c;
            ll sq = sqrtl(d);
            if (sq * sq == d && (sq - a) % 2 == 0)
            {
                ll y = (sq - a) / 2;
                ll x = a + y;
                cout << x << " " << y << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}