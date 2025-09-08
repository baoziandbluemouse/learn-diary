#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N];
int main()
{
    int n, q;
    cin >> n >> q;
    int cnt = 0;
    while (q--)
    {
        int x;
        cin >> x;
        if (a[x] ^ 1 == 0)
        {
            a[x] ^= 1;
            cnt--;
            if (x - 1 >= 1 && a[x - 1] == 1)
            {
                cnt++;
            }
            if (x + 1 <= n && a[x + 1] == 1)
            {
                cnt++;
            }
        }
        else if (a[x] ^ 1 == 1)
        {
            a[x] ^= 1;
            cnt++;
            if (x - 1 >= 1 && a[x - 1] == 1)
            {
                cnt--;
            }
            if (x + 1 <= n && a[x + 1] == 1)
            {
                cnt--;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}