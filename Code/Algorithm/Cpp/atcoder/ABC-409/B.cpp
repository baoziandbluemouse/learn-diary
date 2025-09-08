#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], suffix[N];
int main()
{
    int n;
    cin >> n;
    int maxx = -1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        maxx = max(x, maxx);
        if (x <= 100)
        {
            a[x]++;
        }
        else
        {
            a[100]++;
        }
    }
    for (int i = 100; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] + a[i];
        if (suffix[i] >= i)
        {
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}