#include <iostream>
using namespace std;

void solve()
{
    int len, p, k, s;
    cin >> len >> k >> s >> p;
    int len2 = (len + 2 * p - k) / s + 1;
    cout << len2 << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}