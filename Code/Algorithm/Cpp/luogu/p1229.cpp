#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1, s2; // 存储前序和后序

int main()
{
    cin >> s1 >> s2;
    int len = s1.length();
    ll ans = 1;
    for (int i = 0; i <= len - 2; i++)
    {
        for (int j = 0; j <= len - 1; j++)
        {
            if (s1[i] == s2[j] && s1[i + 1] == s2[j - 1])
            {
                ans = ans * 2ll;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}