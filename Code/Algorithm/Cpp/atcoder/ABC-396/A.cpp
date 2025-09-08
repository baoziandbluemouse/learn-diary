#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 1; i <= n - 2; i++)
    {
        flag = true;
        for (int j = i + 1; j <= i + 2; j++)
        {
            if (a[j] != a[i])
            {
                flag = false;
            }
        }
        if (flag)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    if (!flag)
    {
        cout << "No\n";
    }
    return 0;
}