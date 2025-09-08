#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 9;

int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    bitset<N> bs;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bs[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        bs |= (bs << a[i]);
    }
    cout << bs.count() << '\n';
    return 0;
}