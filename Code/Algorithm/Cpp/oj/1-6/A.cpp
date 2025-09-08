#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010;
int n;
int arr[N];
void dfs(int x, int start, int sum);

int main(void)
{
    cin >> n;
    dfs(1, 1, 0);
    return 0;
}

void dfs(int x, int start, int sum)
{
    if (sum == n)
    {
        bool first = true;
        printf("%d=", n);
        for (int i = 1; i < x; i++)
        {
            if (!first)
            {
                printf("+");
            }
            printf("%d", arr[i]);
            first = false;
        }
        printf("\n");
        return;
    }

    for (int i = start; i < n; i++)
    {
        if (sum + i > n)
            break;
        arr[x] = i;
        dfs(x + 1, i, sum + i);
        arr[x] = 0;
    }
}
