#include <bits/stdc++.h>
using namespace std;
const int N = 3e6 + 10;
int arr[N];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }
    for (int i = 0; i <= 2e5; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            cout << i << " ";
        }
    }
    cout << '\n';
    return 0;
}