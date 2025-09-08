#include <iostream>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    if ((k & 1) == 1)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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