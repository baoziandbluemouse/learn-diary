#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
void dfs(int n, int cnt, int first);

int main(void)
{
    int n;
    cin >> n;
    dfs(n, 0, 1);
    return 0;
}

void dfs(int n, int cnt, int first)
{
    if (n == 0)
    {
        return;
    }
    bool flag_first = false;
    int flag = -1;
    if (n % 2 != 0)
    {
        flag = cnt;
        if (first)
        {
            flag_first = true;
            first = 0;
        }
    }
    dfs(n / 2, cnt + 1, first);
    if (flag == 2)
    {
        cout << "2(2)";
        if (!flag_first)
        {
            cout << "+";
        }
        return;
    }
    if (flag == 1)
    {
        cout << "2";
        if (!flag_first)
        {
            cout << "+";
        }
        return;
    }
    if (flag == 0)
    {
        cout << "2(0)";
        return;
    }
    if (flag > 2)
    {
        cout << "2(";
        dfs(flag, 0, 1);
        cout << ")";
        if (!flag_first)
        {
            cout << "+";
        }
    }
}