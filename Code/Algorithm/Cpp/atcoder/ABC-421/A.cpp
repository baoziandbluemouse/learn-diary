#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, string> mp;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        mp[i] = s;
    }
    int x;
    string y;
    cin >> x >> y;
    if (mp[x] == y)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}