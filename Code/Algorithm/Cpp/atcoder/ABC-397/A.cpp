#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x;
    cin >> x;
    if (x >= 38.0)
    {
        cout << 1 << "\n";
    }
    else if (x >= 37.5 && x < 38.0)
    {
        cout << 2 << "\n";
    }
    else
    {
        cout << 3 << "\n";
    }
    return 0;
}