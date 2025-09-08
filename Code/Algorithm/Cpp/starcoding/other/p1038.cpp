#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
ll a[N], b[N];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    ll ansMAX = 0, ansMIN = 0;
    for (int i = 1; i <= n; i++)
    {
        ansMAX += a[i] * b[i];
    }
    reverse(b + 1, b + n + 1); // 反转
    for (int i = 1; i <= n; i++)
    {
        ansMIN += a[i] * b[i];
    }
    cout << ansMAX << " " << ansMIN << '\n';
    return 0;
}