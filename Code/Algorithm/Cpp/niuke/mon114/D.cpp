#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
// const int N = 100;
using ll = long long;
ll a[N];

int main()
{
    int n;
    ll k;
    ll cnt = 0;
    cin >> n >> k;
    int front = 1, back = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0;
    while (front < back && k - cnt >= 0)
    {
        k -= cnt;
        cnt++;
        if (a[front] > a[back - 1])
        {
            sum = max(sum, sum + a[front]);
            front++;
            k++;
        }
        else
        {
            sum = max(sum, sum + a[back - 1]);
            back--;
            k++;
        }
    }
    cout << sum << "\n";
    return 0;
}