#include <bits/stdc++.h>
using namespace std;
struct pos
{
    int bitter;
    int sour;
};
struct pos a[20];
int st[20];
int n;
int minn = 1e9;
void dfs(int x);
int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].sour >> a[i].bitter;
    }
    dfs(1);
    cout << minn << "\n";
    return 0;
}
void dfs(int x)
{
    if (x > n)
    {
        bool flag = false;
        int sum = 0;
        int mut = 1;
        for (int i = 1; i <= n; i++)
        {
            if (st[i] == 1)
            {
                sum += a[i].bitter;
                mut *= a[i].sour;
                flag = true;
            }
        }
        if (flag)
        {
            minn = min(minn, abs(sum - mut));
        }
        return;
    }
    st[x] = 1; // 1代表选，2代表不选,0代表未考虑
    dfs(x + 1);
    st[x] = 0;

    st[x] = 2;
    dfs(x + 1);
    st[x] = 0;
}