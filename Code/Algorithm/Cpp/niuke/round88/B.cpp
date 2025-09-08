#include <iostream>
using namespace std;

void solve()
{
    bool flag = false;
    int x_a, y_a, x_b, y_b, x_c, y_c;
    cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;
    // 判断经过A的中线是否在坐标轴上
    int m_x = (x_c + x_b) / 2;
    int m_y = (y_c + y_b) / 2;
    if (m_x == x_a && m_x == 0 && x_a == 0)
    {
        // 经过y轴
        flag = true;
    }
    else if (m_y == y_a && m_y == 0 && y_a == 0)
    {
        // 经过x轴
        flag = true;
    }
    // 判断经过B的中线是否在坐标轴上
    m_x = (x_c + x_a) / 2;
    m_y = (y_c + y_a) / 2;
    if (m_x == x_b && m_x == 0 && x_b == 0)
    {
        // 经过y轴
        flag = true;
    }
    else if (m_y == y_b && m_y == 0 && y_b == 0)
    {
        // 经过x轴
        flag = true;
    }
    // 判断经过C的中线是否在坐标轴上
    m_x = (x_a + x_b) / 2;
    m_y = (y_a + y_b) / 2;
    if (m_x == x_c && m_x == 0 && x_c == 0)
    {
        // 经过y轴
        flag = true;
    }
    else if (m_y == y_c && m_y == 0 && y_c == 0)
    {
        // 经过x轴
        flag = true;
    }
    if (flag)
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