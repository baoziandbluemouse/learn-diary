#include <bits/stdc++.h>
using namespace std;
const int N = 120;
char s[N][N], s1[N][N], s2[N][N], s3[N][N], t[N][N];

void change(int n, char s[][N], char s2[][N])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            s2[j][n - i + 1] = s[i][j];
        }
    }
}

int cal(int n, char s[][N], char t[][N])
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] != t[i][j])
                ans++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> t[i][j];
        }
    }
    change(n, s, s1);
    change(n, s1, s2);
    change(n, s2, s3);
    int cnt1 = cal(n, s, t);
    int cnt2 = cal(n, s1, t) + 1;
    int cnt3 = cal(n, s2, t) + 2;
    int cnt4 = cal(n, s3, t) + 3;
    int ans = min(cnt1, min(cnt2, min(cnt3, cnt4)));
    cout << ans << "\n";
}
