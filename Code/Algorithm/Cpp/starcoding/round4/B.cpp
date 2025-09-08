#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool isprime(ll x)
{
    if (x < 2)
    {
        return false;
    }
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;
        for (ll i = a + 1;; i++)
        {
            if (isprime(i))
            {
                cout << i << "\n";
                break;
            }
        }
    }
    return 0;
}