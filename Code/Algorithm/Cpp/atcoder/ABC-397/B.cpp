#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    s = ' ' + s + ' ';
    int cnt = 0;
    for (int i = 1; i <= s.size(); i++)
    {
        if (s[i] == 'i')
        {
            if (s[i + 1] != 'o')
            {
                cnt++;
            }
        }
        else if (s[i] == 'o')
        {
            if (s[i - 1] != 'i')
            {
                cnt++;
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}