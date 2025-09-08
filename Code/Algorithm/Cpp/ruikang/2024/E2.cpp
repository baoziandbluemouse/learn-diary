#include <bits/stdc++.h>

using namespace std;

struct Span
{
    int t, d, p;
    Span(int t, int d, int p) : t(t), d(d), p(p) {}
};

void solve()
{
    int n;
    cin >> n;
    vector<Span> ps;
    for (int i = 0; i < n; i++)
    {
        int t, d, p;
        cin >> t >> d >> p;
        ps.push_back(Span(t, d, p));
    }
    // 按时间序排序，保证dp的无后效性
    sort(ps.begin(), ps.end(), [](auto &a, auto &b)
         { return a.d < b.d; });

    // 这边的5000为时间的上限
    vector<int> dp(5001, 0);

    for (int i = 0; i < n; i++)
    {
        vector<int> dp2(5001, 0);
        int d = ps[i].d, t = ps[i].t;
        for (int j = 0; j <= d - t; j++)
        {
            dp2[j + t] = max(dp2[j + t], dp[j] + ps[i].p);
        }

        for (int j = 0; j <= 5000; j++)
        {
            dp2[j] = max(dp2[j], dp[j]);
            if (j > 0)
                dp2[j] = max(dp2[j], dp2[j - 1]);
        }
        dp.swap(dp2);
    }

    cout << dp[5000] << endl;
}

int main()
{

    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }

    return 0;
}
