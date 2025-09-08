#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> mp;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (mp.count(x) && mp[x] > 0)
        {
            mp[x]--;
        }
    }
    for (auto &x : mp)
    {
        int cnt = x.second;
        for (int i = 0; i < cnt; i++)
        {
            cout << x.first << " ";
        }
    }
    cout << "\n";
    return 0;
}