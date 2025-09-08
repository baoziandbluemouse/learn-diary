#include <iostream>
#include <algorithm>
#define MAX 110
using namespace std;
int arr[MAX];

int main(void)
{
    int n, i = 0, cnt = 0, k = 0, sum = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    k = sum / n;
    for (i = 1; i <= n; i++)
    {
        if (arr[i] - k)
        {
            arr[i + 1] += arr[i] - k;
            cnt++;
        }
    }
    printf("%d\n", cnt);
}