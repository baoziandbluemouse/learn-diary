#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int cnt_0 = 0;
    int cnt_2 = 0;
    int cnt_1 = 0;
    int cnt_3 = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if (i % 4 == 0)
        {
            cnt_0++;
        }
        else if (i % 4 == 2)
        {
            cnt_2++;
        }
        else if (i % 4 == 1)
        {
            cnt_1++;
        }
        else if (i % 4 == 3)
        {
            cnt_3++;
        }
    }
    if (cnt_0 == cnt_3 && cnt_1 == cnt_2)
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Alice\n";
    }
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