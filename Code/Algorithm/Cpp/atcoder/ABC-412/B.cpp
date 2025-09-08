#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> cnt;
    string a, b;
    cin >> a >> b;
    for (auto &x : b)
    {
        cnt[x]++;
    }
    bool flag = true;
    for (int i = a.size(); i >= 1; i--)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            if (!cnt.count(a[i - 1]))
            {
                flag = false;
            }
        }
    }
    if (flag)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}