#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<pair<char, ll>> v;
    for (int i = 0; i < n - 1; i++)
    {
        if (p[i] > p[i + 1])
        {
            if (v.empty() || v.back().first == '<')
            {
                v.push_back({'>', 1});
            }
            else
            {
                v.back().second++;
            }
        }
        else if (p[i] < p[i + 1])
        {
            if (v.empty() || v.back().first == '>')
            {
                v.push_back({'<', 1});
            }
            else
            {
                v.back().second++;
            }
        }
    }
    ll ans = 0;
    int sz = v.size();
    for (int i = 1; i < sz - 1; i++)
    {
        if (v[i].first == '>')
        {
            ans += v[i - 1].second * v[i + 1].second;
        }
    }
    cout << ans << "\n";
    return 0;
}