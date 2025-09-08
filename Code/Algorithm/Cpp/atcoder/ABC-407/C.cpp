#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    ll cnt = 0;
    ll x = 0;
    ll sum = 0;
    for (int i = s.size() - 1; i >= 1; i--)
    {
        cnt += (s[i] - '0' + 1);
        sum += (s[i] - '0');
        s[i - 1] = ((s[i - 1] - '0' + (10 * (s.size() - i)) - sum) % 10) + '0';
    }
    cnt += (s[0] - '0' + 1);
    cout << cnt << "\n";
    return 0;
}