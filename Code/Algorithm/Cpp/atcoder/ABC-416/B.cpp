#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.' && (i == s.size() - 1 || s[i + 1] == '#'))
        {
            s[i] = 'o';
        }
    }
    cout << s << "\n";
    return 0;
}