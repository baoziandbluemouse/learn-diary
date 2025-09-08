#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 110
#define MAXN 10010
int arr[MAXN];
bool cmp(int x, int y)
{
    return x > y;
}

int main(void)
{
    int n, m, i = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (i = m + 1; i <= n; i++)
    {
        sort(arr + 1, arr + m + 1);
        arr[1] += arr[i];
    }
    sort(arr + 1, arr + m + 1, cmp);
    cout << arr[1] << "\n";
    return 0;
}