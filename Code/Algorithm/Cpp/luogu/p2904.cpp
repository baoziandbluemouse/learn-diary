#include <bits/stdc++.h>
using namespace std; // 结合了桶以及hash,这里二维数组也可以用map来，这样就不会有桶大小担忧了
const int N = 676;
int cit[N][N], x, y, ans; // 二维数组，cit[x][y]表示(x城市，y州)这样一个组合的数量

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        x = (a[0] - 'A') * 26 + a[1] - 'A';
        y = (b[0] - 'A') * 26 + b[1] - 'A';
        if (x != y) // x==y时，配对只会配对到自己州，题目也说了不会有这种情况
        {
            cit[x][y]++;
        }
        ans = ans + cit[y][x]; // 注意这里y和x反过来了
    }
    cout << ans << "\n";
    return 0;
}