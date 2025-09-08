#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int add(ll y)
{
    cout << "add " << y << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int mul(ll y)
{
    cout << "mul " << y << "\n"
         << flush;
    int x;
    cin >> x;
    return x;
}

int div(ll y)
{
    cout << "div " << y << "\n"
         << flush;
    int x;
    cin >> x;
    return x;
}

void digit()
{
    cout << "digit\n"
         << flush;
    int x;
    cin >> x;
}

void ans()
{
    cout << "!\n"
         << flush;
    int x;
    cin >> x;
}

void solve()
{
    ll n;
    cin >> n;
    digit();
    digit();
    add(-8);
    add(-4);
    add(-2);
    add(-1);
    mul(n);
    ans();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}