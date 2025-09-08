#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll x, y, lim;
    cin >> x >> y;
    cin >> lim;
    ll cnt_x = 1, cnt_y = 1;
    while (lim--)
    {
        cout << cnt_x << " " << cnt_y << "\n";
        if (cnt_x == x)
            cnt_x = 1;
        else
            cnt_x++;
        if (cnt_y == y)
            cnt_y = 1;
        else
            cnt_y++;
    }
    return 0;
}