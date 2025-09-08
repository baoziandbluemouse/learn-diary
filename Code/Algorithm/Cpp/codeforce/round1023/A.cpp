#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = v[0];
    for (int i = 1; i < n; i++)
    {
        ans = gcd(ans, v[i]);
    }
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i] > ans)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        bool flag1 = false;
        cout << "YES" << "\n";
        for (int i = 0; i < n; i++)
        {
            if (v[i] <= ans)
            {
                cout << 2 << " ";
            }
            else
            {
                if (!flag1)
                {
                    cout << 1 << " ";
                    flag1 = true;
                }
                else
                {
                    cout << 2 << " ";
                }
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "NO" << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}