#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int arr[100];
int a[100];
int b[100];
int n, f;
int ave = -1;
int main(void)
{
    scanf("%d%d", &n, &f);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    a[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        a[i] = arr[i] + a[i - 1];
    }
    for (int i = 0; i < (n - f + 1); i++)
    {
        b[i] = a[i + f] - a[i];
        ave = max(ave, b[i]);
    }
    int average = (ave * 1000) / f;
    printf("%d\n", average);
    return 0;
}
