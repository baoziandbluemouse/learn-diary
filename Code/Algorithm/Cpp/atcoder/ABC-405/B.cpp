#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 110;
int a[N], b[N];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
    }
    int cnt = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int i = 1; i <= m; i++)
        {
            if (b[i] == 0)
            {
                cout << cnt << "\n";
                return 0;
            }
        }
        b[a[i]]--;
        cnt++;
    }
    for (int i = 1; i <= m; i++)
    {
        if (b[i] == 0)
        {
            cout << cnt << "\n";
            return 0;
        }
    }
    return 0;
}