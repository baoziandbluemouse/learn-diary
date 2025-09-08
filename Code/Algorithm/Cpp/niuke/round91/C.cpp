#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<int> premax(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        premax[i] = max(premax[i - 1], a[i]);
    }
    int sum = 0;
    for (int j = n; j >= 1; j--)
    {
        if (premax[j - 1] > a[j])
        {
            sum = max(sum, premax[j - 1] + a[j]);
        }
    }
    cout << sum << "\n";
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