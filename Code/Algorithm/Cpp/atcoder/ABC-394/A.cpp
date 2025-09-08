#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '2')
        {
            ans++;
        }
    }
    for (int i = 1; i <= ans; i++)
    {
        cout << 2;
    }
    cout << "\n";
    return 0;
}