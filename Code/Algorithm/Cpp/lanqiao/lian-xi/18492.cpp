#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
void solve()
{
    int op;
    cin >> op;
    if (op == 1)
    {
        int l, r, k;
        cin >> l >> r >> k;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[r] == k)
        {
            cout << r << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    else if (op == 2)
    {
        int l, r, k;
        cin >> l >> r >> k;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (a[mid] <= k)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (a[l] == k)
        {
            cout << l << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    else if (op == 3)
    {
        int l, r, k;
        cin >> l >> r >> k;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[r] >= k)
        {
            cout << r << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    else
    {
        int l, r, k;
        cin >> l >> r >> k;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (a[mid] > k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (a[r] > k)
        {
            cout << r << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        solve();
    }
    return 0;
}