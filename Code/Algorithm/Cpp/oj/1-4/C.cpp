#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
long long n, f;
double l = 0, r = 2e3, s[N], a[N];

bool check(double mid);

int main(void)
{
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (r - l > 1e-5)
    {
        double mid = (l + r) / 2;
        if (check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << int(r * 1000);
    return 0;
}

bool check(double mid)
{
    for (int i = 1; i <= n; i++)
    {
        s[i] = s[i - 1] + a[i] - mid;
    }
    double minn = 0;
    for (int i = f; i <= n; i++)
    {
        minn = min(minn, s[i - f]);
        if (s[i] - minn >= 0)
        {
            return true;
        }
    }
    return false;
}