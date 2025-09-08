#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N];
int main()
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
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i + 1])
        {
            flag = false;
        }
        if (!flag)
        {
            break;
        }
    }
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}