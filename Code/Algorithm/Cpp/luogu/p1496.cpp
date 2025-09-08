#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4 + 9;

ll sta[N], en[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> sta[i] >> en[i];
    }
    sort(sta + 1, sta + 1 + n);
    sort(en + 1, en + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += abs(sta[i] - en[i]);
        if (i + 1 <= n)
        {
            if (en[i] > sta[i + 1])
            {
                ans = ans - (en[i] - sta[i + 1]);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}