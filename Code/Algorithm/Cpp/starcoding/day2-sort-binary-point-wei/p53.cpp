#include <bits/stdc++.h> //异或运算，异或前缀和
using namespace std;
const int N = 2e5 + 9;
int prexor[N];
void solve()
{
    int len = 0;
    int a, b;
    cin >> a >> b;
    int y = prexor[a - 1] ^ b;
    if (y == 0)
    {
        len = a;
    }
    else if (y == a)
    {
        len = a + 2;
    }
    else
    {
        len = a + 1;
    }
    cout << len << '\n';
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= 2e5; i++)
    {
        prexor[i] = prexor[i - 1] ^ i;
    }
    while (t--)
    {
        solve();
    }
    return 0;
}