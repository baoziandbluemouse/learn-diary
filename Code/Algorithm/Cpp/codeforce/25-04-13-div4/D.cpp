#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve()
{
    string s;
    string p;
    cin >> p >> s;
    int n = p.size();
    int m = s.size();
    if (m < n || m > 2 * n || s[0] != p[0])
    {
        cout << "NO\n";
        return;
    }
    vector<int> aa, bb;
    // 分块
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i] != p[i - 1])
        {
            aa.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    aa.push_back(cnt);
    cnt = 1;
    for (int i = 1; i < m; i++)
    {
        if (s[i] != s[i - 1])
        {
            bb.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    bb.push_back(cnt);
    // compare
    if (aa.size() != bb.size())
    {
        cout << "NO\n";
        return;
    }
    else
    {
        for (int i = 0; i < aa.size(); i++)
        {
            if (bb[i] < aa[i] || bb[i] > 2 * aa[i])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}