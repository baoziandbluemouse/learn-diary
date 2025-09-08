#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
// const int N = 50;
using ll = long long;
ll a[N];

int main()
{
    ll n, q;
    cin >> n >> q;
    ll start = 0, end = n;
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
    }
    while (q--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            ll p;
            cin >> p;
            ll idx = (p + start - 1 + end) % end;
            ll x;
            cin >> x;
            a[idx] = x;
        }
        else if (opt == 2)
        {
            ll p;
            cin >> p;
            ll idx = (p + start - 1 + end) % end;
            cout << a[idx] << "\n";
        }
        else if (opt == 3)
        {
            ll k;
            cin >> k;
            start = (start + k) % end;
        }
    }
    return 0;
}