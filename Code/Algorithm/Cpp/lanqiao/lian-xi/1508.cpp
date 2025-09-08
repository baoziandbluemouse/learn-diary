#include <iostream>
#include <bitset>
#include <algorithm>
using namespace std;
const int N = 100;
bitset<N> col;
bitset<N> ls;
bitset<N> rs;
int n, res;
void dfs(int row)
{
    if (row > n)
    {
        res++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!col[i] && !ls[i + row] && !rs[i - row + n])
        {
            col[i] = true;
            ls[i + row] = true;
            rs[i - row + n] = true;
            dfs(row + 1);
            col[i] = false;
            ls[i + row] = false;
            rs[i - row + n] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << res << "\n";
    return 0;
}