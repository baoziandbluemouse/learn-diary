#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int dif[N];
int main()
{
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        dif[l]++;
        dif[r + 1]--;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dif[i];
        if (ans % 2 == 0)
        {
            cout << s[i - 1];
        }
        else
        {
            cout << t[i - 1];
        }
    }
    cout << "\n";
    return 0;
}