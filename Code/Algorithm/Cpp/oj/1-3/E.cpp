#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 1000
using namespace std;
char str[MAX];
int arr[MAX];
int main(void)
{
    int k;
    scanf("%250s", str);
    cin >> k;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        arr[i] = str[i] - '0';
    }
    int l = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int i = 0; i < len; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                for (int j = i; j < len; j++)
                    arr[j] = arr[j + 1];
                len--;
                break;
            }
        }
    }
    int i = 0;
    while (arr[i] == 0 && l < len - 1)
    {
        l++;
        i++;
    }
    for (int i = l; i < len; i++)
        printf("%d", arr[i]);
    return 0;
}