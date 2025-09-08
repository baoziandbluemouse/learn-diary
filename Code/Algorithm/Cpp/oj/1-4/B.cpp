#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 100005
using namespace std;
int arr[MAX];
int ans = -1;
int n, m;
bool check(int x);
void merge(int left, int right);
int main(void)
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    merge(1, 2 << 29);
    cout << ans << "\n";
    return 0;
}

void merge(int left, int right)
{
    if (right - left < 0)
    {
        return;
    }
    int mid = left + ((right - left) >> 1);
    if (check(mid))
    {
        merge(mid + 1, right);
        ans = max(ans, mid);
    }
    else
    {
        merge(left, mid - 1);
    }
}

bool check(int x)
{
    int i = 0, num = 1, now = 0;
    for (i = 1; i < n; i++)
    {
        if (arr[i] - arr[now] >= x)
        {
            now = i;
            num++;
        }
    }
    return num >= m;
}