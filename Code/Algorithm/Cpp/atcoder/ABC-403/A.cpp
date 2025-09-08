#include <iostream>
using namespace std;
const int N = 110;
int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for (int i = 1; i <= n; i += 2)
    {
        sum += a[i];
    }
    cout << sum << "\n";
    return 0;
}