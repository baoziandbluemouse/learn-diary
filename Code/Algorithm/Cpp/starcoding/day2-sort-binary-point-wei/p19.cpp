#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
typedef long long ll;
ll arr[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);
    ll sum = 0;
    int l = 1, r = n;
    while (l != r)
    {
        if (arr[r] + arr[l] > m)
        {
            sum += r - l;
            r--;
        }
        else
        {
            l++;
        }
    }
    cout << sum << '\n';
    return 0;
}