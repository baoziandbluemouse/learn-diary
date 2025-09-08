#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
int n, c;
int arr[N];
bool check(ll mid)
{
    int j = 1;
    int cnt = 1; // 注意这里牛已经在第一个位置放了一头了
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] - arr[j] >= mid)
        {
            cnt++;
            j = i;
        }
    }
    return cnt >= c;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    ll l = 0, r = 1e9 + 10, mid = 0;
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
    cout << l << '\n';
    return 0;
}