#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
// const int N = 100;
ll a[N];
int main()
{
    int n, g;
    cin >> n >> g;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x % g == 0)
        {
            a[i] = 0;
        }
        else
        {
            a[i] = 1;
        }
    }
    ll ans = 0;
    int l = 1, cnt = 0;
    for (int r = 1; r <= n; r++)
    {
        cnt += a[r];
        while (cnt > 1)
        {
            cnt = cnt - a[l];
            l++;
        }
        if (r - l + 1 >= 2 && cnt <= 1)
        {
            ans += r - l;
        }
    }
    cout << ans << "\n";
    return 0;
}