#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (a[i] * i);
    }
    cout << sum << "\n";
    return 0;
}