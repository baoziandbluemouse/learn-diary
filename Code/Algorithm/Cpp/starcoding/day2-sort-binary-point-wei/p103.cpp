#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
typedef long long ll;

ll arr[N];

void solve()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    ll minn = arr[1], maxx = arr[1], sum = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        minn = min(arr[i], minn);
        maxx = max(arr[i], maxx);
        while (maxx - minn > m)
        {
            j++;
            minn = *min_element(arr + j, arr + i + 1);
            maxx = *max_element(arr + j, arr + i + 1);
        }
        sum += i - j + 1;
    }
    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}