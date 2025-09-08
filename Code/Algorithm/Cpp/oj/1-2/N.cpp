#include <iostream>
#include <cstdio>
#include <algorithm>
typedef long long ll;
using namespace std;
ll arr[80] = {0, 1, 2, 4};
ll solve(int x);
int main(void)
{
    int n;
    cin >> n;
    while (n != 0)
    {
        cout << solve(n) << "\n";
        cin >> n;
    }
    return 0;
}

ll solve(int x)
{
    for (int i = 4; i <= x; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[x];
}