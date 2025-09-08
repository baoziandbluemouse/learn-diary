#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '1' && s[i - 1] == '1')
        {
            cnt++;
            s[i] = '0';
        }
    }
    cout << cnt;
    return 0;
}
