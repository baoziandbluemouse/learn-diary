#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c)
    {
        if (b < d)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    else if (a > c)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}