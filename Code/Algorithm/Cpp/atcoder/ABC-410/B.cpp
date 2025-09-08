#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (x != 0)
        {
            a[x]++;
            cout << x << " ";
        }
        else
        {
            int idx = 100;
            int minn = 1e9;
            int j;
            for (j = n; j >= 1; j--)
            {
                if (minn >= a[j])
                {
                    idx = j;
                    minn = a[j];
                }
            }
            a[idx]++;
            cout << idx << " ";
        }
    }
    cout << "\n";
    return 0;
}