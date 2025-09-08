#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n + 1, 0);
    int num1 = 1;
    int num2 = 2;
    int num3 = 3;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (p[i] % 3 == 1)
        {
            cout << num2 << " ";
            num2 += 3;
        }
        else if (p[i] % 3 == 2)
        {
            cout << num1 << " ";
            num1 += 3;
        }
        else if (p[i] % 3 == 0)
        {
            cout << num3 << " ";
            num3 += 3;
        }
    }
    cout << "\n";
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}