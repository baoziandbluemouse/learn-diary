#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
using ll = long long;
ll a[N * 2];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n * 2 + 1);
    int l = 1, r = 2 * n;
    ll sum = 0;
    while (l < r)
    {
        sum += a[l] * a[r];
        l++;
        r--;
    }
    cout << sum << "\n";
    return 0;
}