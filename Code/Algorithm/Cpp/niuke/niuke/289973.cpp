#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll x = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            x = x + a[i];
        }
        else
        {
            x = x - a[i];
        }
    }
    cout << x << "\n";
    return 0;
}