#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n, m;
    cin >> n >> m;
    ll sum = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sum += b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll k = 0;
    int j = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        while (j < n && a[i] + b[j] < m)
        {
            j++;
        }
        if (j == n)
        {
            break;
        }
        k++;
        j++;
    }
    cout << sum - k * m << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}