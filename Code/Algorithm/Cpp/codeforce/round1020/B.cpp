#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n == k)
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " ";
        }
        return;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            if (i == k)
            {
                continue;
            }
            cout << i << " ";
        }
        cout << k << "\n";
    }
}

int main()
{
    int _t;
    cin >> _t;
    while (_t--)
    {
        solve();
    }
    return 0;
}