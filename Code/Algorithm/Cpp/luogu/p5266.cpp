#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<string, ll> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int opt, score;
        string name;
        cin >> opt;
        if (opt == 1)
        {
            cin >> name >> score;
            mp[name] = score;
            cout << "OK" << "\n";
        }
        else if (opt == 2)
        {
            cin >> name;
            if (mp.count(name))
            {
                cout << mp[name] << "\n";
            }
            else
            {
                cout << "Not found" << "\n";
            }
        }
        else if (opt == 3)
        {
            cin >> name;
            if (mp.count(name))
            {
                mp.erase(name);
                cout << "Deleted successfully" << "\n";
            }
            else
            {
                cout << "Not found" << "\n";
            }
        }
        else
        {
            cout << mp.size() << "\n";
        }
    }
    return 0;
}