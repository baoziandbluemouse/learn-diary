#include <bits/stdc++.h>
using namespace std;
const int N = 110;

string s[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    map<string, int> mp;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            mp[s[i] + s[j]] = 1;
        }
    }
    cout << mp.size();

    return 0;
}