#include <iostream>
#include <bitset>
using namespace std;
const int N = 15;
int a[N];
bitset<N> vis;

int main()
{
    bool flag1 = false;
    bool flag2 = false;
    for (int i = 1; i <= 7; i++)
    {
        int x;
        cin >> x;
        a[x]++;
        if (a[x] >= 3 && flag1 != true)
        {
            flag1 = true;
            vis[x] = true;
        }
    }
    if (flag1 == false)
    {
        cout << "No\n";
        return 0;
    }
    for (int i = 1; i <= 13; i++)
    {
        if (vis[i])
        {
            continue;
        }
        if (a[i] >= 2)
        {
            flag2 = true;
            break;
        }
    }
    if (flag1 && flag2)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}