#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int arr[N];
int st[N];
int n;
int cnt = 0;
void dfs(int x);
bool isprime(int num);

int main(void)
{
    cin >> n;
    arr[1] = 1;
    dfs(2);
    return 0;
}

void dfs(int x)
{
    if (cnt == 10)
    {
        exit(0);
    }
    if (x > n)
    {
        if (isprime(arr[n] + 1))
        {
            cnt++;
            for (int i = 1; i <= n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            arr[x] = i;
            if (isprime(arr[x] + arr[x - 1]))
            {
                dfs(x + 1);
            }
            st[i] = 0;
            arr[x] = 0;
        }
    }
}

bool isprime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}