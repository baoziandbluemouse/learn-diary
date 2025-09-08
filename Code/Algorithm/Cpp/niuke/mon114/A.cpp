#include <iostream>
using namespace std;
const int N = 10;
int a[N], b[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int x = a[i] - 1;
        if (i == 1)
        {
            x += 2;
        }
        if (x > 5)
        {
            b[i] = 5;
        }
        else
        {
            b[i] = x;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
    return 0;
}