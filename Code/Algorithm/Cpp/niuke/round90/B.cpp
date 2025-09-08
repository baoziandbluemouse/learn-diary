#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '5')
        {
            cnt++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (s[i] != '5')
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}