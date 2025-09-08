#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
bitset<N> vis;

int main()
{
    int n = 1e9;
    vis[0] = vis[1] = true;
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            cout << i << ",";
        }
    }

    for (int sub = s; sub > 0; sub = (sub - 1) & s)
    {
    }
    return 0;
}