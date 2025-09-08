#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    int c;
    cin >> n >> c;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(a[i] + c))
        {
            ans += mp[a[i] + c];
        }
    }
    cout << ans << "\n";
    return 0;
}