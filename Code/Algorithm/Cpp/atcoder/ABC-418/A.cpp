#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 3)
    {
        cout << "No\n";
        return 0;
    }
    if (s[n - 1] == 'a' && s[n - 2] == 'e' && s[n - 3] == 't')
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    return 0;
}