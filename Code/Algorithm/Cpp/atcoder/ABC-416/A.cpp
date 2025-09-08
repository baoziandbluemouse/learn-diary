#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    s = " " + s;
    bool flag = true;
    for (int i = l; i <= r; i++)
    {
        if (s[i] != 'o')
        {
            flag = false;
            break;
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