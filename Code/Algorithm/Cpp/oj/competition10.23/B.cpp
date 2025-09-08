#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    int c, d;
    cin >> c >> d;
    int p = c ^ d;
    ll ans = 1;
    for (int i = 0; i < 20; i++)
    {
        if (((p >> i) & 1) == 0)
        {
            ans *= 3;
        }
    }
    cout << ans << "\n";
    return 0;
}