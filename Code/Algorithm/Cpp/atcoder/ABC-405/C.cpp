#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 3e5 + 10;
using ll = long long;
ll a[N], prefix[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    ll ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += prefix[i - 1] * a[i];
    }
    cout << ans << "\n";
    return 0;
}