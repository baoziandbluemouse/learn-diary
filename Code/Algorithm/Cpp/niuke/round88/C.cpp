#include <iostream>
using namespace std;

void solve()
{
    bool flag = false;
    int x_a, y_a, x_b, y_b, x_c, y_c;
    cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;
    if (x_a * 2 == x_b + x_c || x_b * 2 == x_a + x_c || x_c * 2 == x_a + x_b)
        flag = true;
    if (y_a * 2 == y_b + y_c || y_b * 2 == y_a + y_c || y_c * 2 == y_a + y_b)
        flag = true;
    if (flag)
        cout << "YES" << "\n";
    else
        cout << "NO" << "\n";
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