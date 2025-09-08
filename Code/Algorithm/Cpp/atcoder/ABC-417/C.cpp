#include <iostream>
#include <map>
using namespace std;
using ll = long long;
const int N = 2e5 + 10;
int a[N];
int main()
{
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = i - a[i];
        int p = a[i] + i;
        if (mp.count(t))
        {
            ans += mp[t];
        }
        mp[p]++;
    }
    cout << ans << "\n";
    return 0;
}