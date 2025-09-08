#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N], suffix[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for (int i = 100; i >= 1; i--)
    {
        suffix[i] = suffix[i + 1] + a[i];
    }
    int k;
    cin >> k;
    cout << suffix[k] << "\n";
    return 0;
}