#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define MAX 1000000
ll arr[MAX] = {0, 1, 2};
int k[100000];
int main(void)
{
    int t, maxx = 0;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> k[i];
        maxx = max(maxx, k[i]);
    }
    for (int i = 3; i <= maxx; i++)
    {
        arr[i] = (arr[i - 2] + 2 * arr[i - 1]) % 32767;
    }
    for (int i = 1; i <= t; i++)
    {
        cout << arr[k[i]] << "\n";
    }
    return 0;
}