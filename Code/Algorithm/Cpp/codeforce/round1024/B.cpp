#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = abs(x);
    }
    int b = a[1];
    sort(a.begin() + 1, a.end());
    if (a[(n + 1) / 2] == b)
    {
        cout << "YES\n";
    }
    else
    {
        int x_left = 0, x_right = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < b)
            {
                x_left++;
            }
            else if (a[i] > b)
            {
                x_right++;
            }
        }
        if (n % 2 == 0)
        {
            if (x_left + 1 == x_right)
            {
                cout << "YES\n";
                return;
            }
            else
            {
                if (x_right > x_left)
                {
                    cout << "YES\n";
                    return;
                }
            }
            swap(x_left, x_right);
            if (x_left + 1 == x_right)
            {
                cout << "YES\n";
                return;
            }
            else
            {
                if (x_left > x_right)
                {
                    cout << "YES\n";
                    return;
                }
            }
            cout << "NO\n";
        }
        else
        {
            if (x_left == x_right)
            {
                cout << "YES\n";
                return;
            }
            else
            {
                if (x_right > x_left)
                {
                    cout << "YES\n";
                    return;
                }
            }
            swap(x_left, x_right);
            if (x_left == x_right)
            {
                cout << "YES\n";
                return;
            }
            else
            {
                if (x_left > x_right)
                {
                    cout << "YES\n";
                    return;
                }
            }
            cout << "NO\n";
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}