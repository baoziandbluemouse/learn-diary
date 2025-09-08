#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll w, h;
    cin >> w >> h;
    ll l = 2;
    while (w % l != 0 || h % l != 0)
    {
        if (l == min(w, h))
        {
            break;
        }
        l++;
    }
    if ((w % l != 0 || h % l != 0) && l == min(w, h))
    {
        cout << 0 << "\n";
    }
    else
    {
        ll n = w / l * h / l;
        cout << n << "\n";
    }
    return 0;
}