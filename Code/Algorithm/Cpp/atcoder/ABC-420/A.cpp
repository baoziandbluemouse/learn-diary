#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int ans = x + y;
    if (ans % 12 == 0)
    {
        cout << 12 << "\n";
    }
    else
    {
        cout << ans % 12 << "\n";
    }
    return 0;
}