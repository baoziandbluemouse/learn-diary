#include <bits/stdc++.h>
using namespace std;
const int N = 150;
int a[N];
int b[N];
vector<int> v(N);
int n;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        b[n + 1] = 0;
        for (int i = 1; i <= n; i++)
        {
            v[i] = a[i] - b[i + 1];
        }
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (v[i] > 0)
            {
                sum += v[i];
            }
        }
        int maxx = max(a[n], sum);
        cout << maxx << "\n";
        v.clear();
    }
    return 0;
}