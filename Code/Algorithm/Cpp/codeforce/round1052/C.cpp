#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            ans.push_back(i + 1);
        }
        else
        {
            int j = i;
            while (j + 1 < n && s[j + 1] == '0')
            {
                j++;
            }
            if (j - i + 1 == 1)
            {
                cout << "NO\n";
                return;
            }
            for (int k = j; k >= i; k--)
            {
                ans.push_back(k + 1);
            }
            i = j;
        }
    }
    cout << "YES\n";
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}