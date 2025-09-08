#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n;
int arr[1010];
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i / 2; j++)
        {
            arr[i] += arr[j];
        }
        arr[i]++;
    }
    cout << arr[n] << "\n";
    return 0;
}