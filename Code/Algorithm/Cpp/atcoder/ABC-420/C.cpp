#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int n, q;
ll a[N];
ll b[N];

int main()
{
    cin >> n >> q;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        sum += min(a[i], b[i]);
    }
    while (q--)
    {
        char flag;
        int p;
        ll val;
        cin >> flag >> p >> val;
        sum -= min(a[p], b[p]);
        if (flag == 'A')
        {
            a[p] = val;
        }
        else
        {
            b[p] = val;
        }
        sum += min(a[p], b[p]);
        cout << sum << "\n";
    }
    return 0;
}