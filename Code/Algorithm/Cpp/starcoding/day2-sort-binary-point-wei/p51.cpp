#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;

ll f(int x)
{
    ll res = 0;
    while (x > 0)
    {
        if (x & 1 == 1)
            res++;
        x >>= 1;
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cout << f(x) << ' ';
    }
    cout << '\n';
    return 0;
}