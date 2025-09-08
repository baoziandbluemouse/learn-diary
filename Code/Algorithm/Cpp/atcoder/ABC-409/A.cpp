#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s1, s2;
    cin >> n;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == 'o' && s2[i] == 'o')
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}