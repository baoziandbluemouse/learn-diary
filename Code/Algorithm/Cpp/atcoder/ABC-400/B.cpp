#include <iostream>
using namespace std;
using ll = long long;
const int N = 110;
ll a[N];
ll prefix[N];
int main()
{
    int n, m;
    cin >> n >> m;
    bool flag = false;
    a[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        if (a[i - 1] * n > 1e9)
        {
            flag = true;
            break;
        }
        a[i] = a[i - 1] * n;
    }
    if (flag)
    {
        cout << "inf" << "\n";
        return 0;
    }
    prefix[0] = 1;
    for (int i = 1; i <= m; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
        if (prefix[i] > 1e9)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "inf\n";
    }
    else
    {
        cout << prefix[m] << "\n";
    }
    return 0;
}