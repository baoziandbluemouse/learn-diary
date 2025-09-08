#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
int a[N];
map<ll, ll> mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(a[i] + c))
        {
            ans += mp[a[i] + c];
        }
    }
    cout << ans << "\n";
    return 0;
}