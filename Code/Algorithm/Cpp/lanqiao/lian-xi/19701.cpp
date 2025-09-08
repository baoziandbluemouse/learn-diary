#include <iostream>
using namespace std;
int change(int x, int u)
{
    int sum = 0;
    while (x)
    {
        int w = x % u;
        x /= u;
        sum += w;
    }
    return sum;
}
bool check(int x)
{
    int a = change(x, 2);
    int b = change(x, 4);
    return a == b;
}
int main()
{
    int ans = 0;
    for (int i = 1; i <= 2024; i++)
    {
        if (check(i))
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}