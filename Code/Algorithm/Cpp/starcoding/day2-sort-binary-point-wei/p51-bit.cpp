#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cout << bitset<32>(x).count() << '\n';
    }
    cout << '\n';
    return 0;
}