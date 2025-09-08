#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 1e5 + 10;
ll prefix[N];
ll b[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    ll maxx = -1;
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + b[i];
        if (i > 10)
        {
            prefix[i] -= b[i - 10];
        }
        maxx = max(maxx, prefix[i]);
    }
    cout << maxx << "\n";
    return 0;
}