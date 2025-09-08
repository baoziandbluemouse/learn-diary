#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    int maxx = -1;
    int minn = 1e9 + 10;
    int max_cnt = 0;
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > maxx)
        {
            maxx = v[i];
            max_cnt = 1;
        }
        else if (v[i] == maxx)
        {
            max_cnt++;
        }
        if (v[i] < minn)
        {
            minn = v[i];
        }
        cnt += v[i];
    }
    if (maxx <= k)
    {
        if (cnt % 2 == 0)
        {
            cout << "Jerry\n";
        }
        else
        {
            cout << "Tom\n";
        }
    }
    else
    {
        if (max_cnt == 1)
        {
            if (maxx - 1 - minn > k)
            {
                cout << "Jerry\n";
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    cout << "Jerry\n";
                }
                else
                {
                    cout << "Tom\n";
                }
            }
        }
        else if (max_cnt > 1)
        {
            if (maxx - minn > k)
            {
                cout << "Jerry\n";
            }
            else
            {
                if (cnt % 2 == 0)
                {
                    cout << "Jerry\n";
                }
                else
                {
                    cout << "Tom\n";
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}