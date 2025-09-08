#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int prefix[N], a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i; j <= n - 1; j++)
        {
            cout << prefix[j] - prefix[i - 1] << " ";
        }
        cout << "\n";
    }
    return 0;
}