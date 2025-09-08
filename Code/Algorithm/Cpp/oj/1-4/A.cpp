#include <iostream>
#define MAX 50010
using namespace std;
int arr[MAX];
int n, m, l;

int f(int x);
int operation(int left, int right);
int main(void)
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[n + 1] = l;

    cout << operation(1, l) << "\n";

    return 0;
}

int f(int x)
{
    int ans = 0;
    int t = 0;
    int len = n + 1;
    for (int i = 1; i <= len; i++)
    {
        if (arr[i] - t >= x)
        {
            t = arr[i];
        }
        else
        {
            ans++;
        }
    }
    return ans;
}

int operation(int left, int right)
{
    if (left == right)
    {
        return left;
    }
    int mid = (left + right + 1) >> 1;
    if (f(mid) <= m)
    {
        return operation(mid, right);
    }
    else
    {
        return operation(left, mid - 1);
    }
}
