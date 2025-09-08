#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
typedef long long ll;
int arr[N];
int n, q, x;
bool check(ll mid)
{
    return arr[mid] < x;
}
void solve(void)
{
    cin >> x;
    ll l = 0, r = n + 1, mid = 0;
    while (l + 1 != r)
    {
        mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    if (arr[r] == x)
    {
        cout << r << " "; // 选l会得出重复数字中的第一个，选r会得出重复数字中的最后一个
    }
    else
    {
        cout << -1 << " ";
    }
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    while (q--)
    {
        solve();
    }
    cout << '\n';
    return 0;
}