#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    for (int i = len - 1; i > 0; i--)
    {
        if (s[i] == 'A' && s[i - 1] == 'W')
        {
            s[i] = 'C';
            s[i - 1] = 'A';
        }
    }
    cout << s << "\n";
    return 0;
}