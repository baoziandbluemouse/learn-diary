#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    ll k = n / 2;
    if (n % 2)
    {
        cout << k * (k + 1) + 1;
    }
    else
    {
        cout << k * k + 1;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}