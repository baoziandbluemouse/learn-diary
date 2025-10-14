#include <bits/stdc++.h>
using namespace std;
struct node
{
    double x, y;
} a, b, c, d;

double len1, len2;
double cal(double l)
{ // 计算走l秒后，2点的距离
    double x1, x2, y1, y2;
    if (l >= len1)
        x1 = b.x, y1 = b.y;
    else
        x1 = a.x + (b.x - a.x) / len1 * l, y1 = a.y + (b.y - a.y) / len1 * l;
    if (l >= len2)
        x2 = d.x, y2 = d.y;
    else
        x2 = c.x + (d.x - c.x) / len2 * l, y2 = c.y + (d.y - c.y) / len2 * l;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve()
{
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    len1 = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    len2 = sqrt((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y));
    double l = 0, r = min(len1, len2), m1, m2;
    while (r - l >= 1e-9)
    { // 二分第一段走的时间
        m1 = (2 * l + r) / 3;
        m2 = (l + 2 * r) / 3;
        if (cal(m1) >= cal(m2))
            l = m1;
        else
            r = m2;
    }
    double ans = cal(l);

    l = min(len1, len2), r = max(len1, len2), m1, m2;
    while (r - l >= 1e-9)
    { // 二分第二段走的时间
        m1 = (2 * l + r) / 3;
        m2 = (l + 2 * r) / 3;
        if (cal(m1) >= cal(m2) - 1e-9)
            l = m1;
        else
            r = m2;
    }
    ans = min(ans, cal(l));
    cout << fixed << setprecision(16) << ans << endl;
}

int main()
{
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}