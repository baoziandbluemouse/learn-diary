#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "R" + s + "R";
    int ans = 0, pre = 0;
    for (int i = 0; i < n + 2; i++)
    {
        if (s[i] == 'L')
            continue;
        ans = max(ans, i - pre);
        pre = i;
    }
    cout << ans << '\n';
    return 0;
}