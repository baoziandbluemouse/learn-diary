#include <iostream>
#include <map>
using namespace std;
const int N = 3e5 + 10;
map<int, int> mp;
int a[N];
int n;

int getidx(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    for (auto it = mp.rbegin(); it != mp.rend(); it++)
    {
        if (it->second == 1)
        {
            cout << getidx(it->first) << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}