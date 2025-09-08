#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N], dif[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        dif[l]++;
        dif[r + 1]--;
    }
    int minn = 1e9;
    for (int i = 1; i <= n; i++)
    {
        a[i] = a[i - 1] + dif[i];
        minn = min(a[i], minn);
    }
    cout << minn << "\n";
    return 0;
}