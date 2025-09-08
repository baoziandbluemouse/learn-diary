#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
void dfs(int x, char a, char b, char c); // x代表第几个盘子
int main(void)
{
    char a, b, c;
    cin >> n;
    cin.ignore();
    cin >> a;
    cin.ignore();
    cin >> b;
    cin.ignore();
    cin >> c;
    cin.ignore();
    dfs(n, a, b, c);
    return 0;
}

void dfs(int x, char a, char b, char c)
{
    if (x == 1)
    {
        cout << a << "->" << x << "->" << b << "\n";
        return;
    }
    dfs(x - 1, a, c, b);
    cout << a << "->" << x << "->" << b << "\n";
    dfs(x - 1, c, b, a);
}