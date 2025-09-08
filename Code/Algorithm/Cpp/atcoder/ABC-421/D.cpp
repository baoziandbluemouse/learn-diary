#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct seg
{
    char dir;
    ll count;
};

int main()
{
    ll Rt, Ct, Ra, Ca;
    cin >> Rt >> Ct >> Ra >> Ca;
    ll n;
    int m, L;
    cin >> n >> m >> L;
    vector<seg> segsS(m);
    vector<seg> segsT(L);
    for (int i = 0; i < m; i++)
        cin >> segsS[i].dir >> segsS[i].count;
    for (int i = 0; i < L; i++)
        cin >> segsT[i].dir >> segsT[i].count;
    ll dx = Rt - Ra; // 行差
    ll dy = Ct - Ca; // 列差
    ll ans = 0;      // 相遇次数

    int is = 0, it = 0;
    ll rs = segsS[is].count;
    ll rt = segsT[it].count;
    while (is < m && it < L)
    {
        ll len = min(rs, rt);
        char sd = segsS[is].dir;
        char td = segsT[it].dir;

        ll ddx = 0, ddy = 0;
        if (sd == 'U')
            ddx -= 1;
        else if (sd == 'D')
            ddx += 1;
        else if (sd == 'L')
            ddy -= 1;
        else if (sd == 'R')
            ddy += 1;

        if (td == 'U')
            ddx += 1;
        if (td == 'D')
            ddx -= 1;
        else if (td == 'L')
            ddy += 1;
        else if (td == 'R')
            ddy -= 1;

        if (ddx == 0 && ddy == 0)
        { // 方向完全一致
            if (dx == 0 && dy == 0)
            { // 初始位置相同，则一直相遇，反之不遇
                ans += len;
            }
        }
        else if (ddx == 0 && ddy != 0)
        { // 列移动方向不同
            if (dx == 0)
            { // 行相同则可能相遇
                if (dy % ddy == 0)
                { // 能整除则能相遇
                    ll i = -dy / ddy;
                    if (i >= 1 && i <= len)
                    {
                        ans++;
                    }
                }
            }
        }
        else if (ddy == 0 && ddx != 0)
        { // 同理
            if (dy == 0)
            {
                if (dx % ddx == 0)
                {
                    ll i = -dx / ddx;
                    if (i >= 1 && i <= len)
                    {
                        ans++;
                    }
                }
            }
        }
        else
        {
            if (dx * ddy == dy * ddx)
            { // dx/ddx = dy/ddy
                if (dx % ddx == 0)
                {
                    ll i = -dx / ddx;
                    if (i >= 1 && i <= len)
                    {
                        ans++;
                    }
                }
            }
        }

        dx += len * ddx;
        dy += len * ddy;
        rs -= len;
        rt -= len;
        if (rs == 0)
        {
            is++;
            if (is < m)
            {
                rs = segsS[is].count;
            }
        }
        if (rt == 0)
        {
            it++;
            if (it < L)
            {
                rt = segsT[it].count;
            }
        }
    }
    cout << ans << endl;

    return 0;
}