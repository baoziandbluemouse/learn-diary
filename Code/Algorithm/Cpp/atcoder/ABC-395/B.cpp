#include <bits/stdc++.h>
using namespace std;
const int N = 55;

char g[N][N];

void solve(int x, int y)
{
    char c;
    if (x & 1)
    {
        c = '#';
    }
    else
    {
        c = '.';
    }
    for (int i = x; i <= y; i++)
    {
        for (int j = x; j <= y; j++)
        {
            g[i][j] = c;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j = n + 1 - i;
        if (i <= j)
        {
            solve(i, j);
        }
        else
        {
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << g[i][j];
        }
        cout << "\n";
    }
    return 0;
}