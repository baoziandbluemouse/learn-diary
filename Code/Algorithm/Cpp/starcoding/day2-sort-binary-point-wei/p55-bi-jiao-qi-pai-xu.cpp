#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;

struct book
{
    int a, b, c;
} p[N];

bool cmp(struct book a, struct book b) // 自定义比较器 以降序为例，如果你要降序，那么a>b就要返回true,否则返回false
{
    if (a.a != b.a)
    {
        return a.a > b.a;
    }
    if (a.b != b.b)
    {
        return a.b > b.b;
    }
    return a.c > b.c;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].a >> p[i].b >> p[i].c;
    }
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        cout << p[i].a << ' ' << p[i].b << ' ' << p[i].c << '\n';
    }
    return 0;
}