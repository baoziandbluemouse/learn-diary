#include <bits/stdc++.h> //运用异或性质+结合律,a^b^c=a^(b^c)+交换律,a^b^a=a^a^b=0^b=b
using namespace std;     // 异或性质：a^a=0,a^0=a
const int N = 1e3 + 10;
typedef long long ll;
ll arr[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res ^= arr[i];
        }
        cout << res << '\n';
    }
}