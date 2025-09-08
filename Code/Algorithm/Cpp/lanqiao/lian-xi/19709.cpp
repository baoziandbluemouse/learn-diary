#include <iostream>
using namespace std;

bool check(int x)
{
    int cnt = 0;
    while (x)
    {
        int w = x % 10;
        cnt++;
        if ((cnt & 1) == 1)
        {
            if ((w & 1) != 1)
            {
                return false;
            }
        }
        else
        {
            if ((w & 1) != 0)
            {
                return false;
            }
        }
        x /= 10;
    }
    return true;
}
int main()
{
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (check(i))
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}