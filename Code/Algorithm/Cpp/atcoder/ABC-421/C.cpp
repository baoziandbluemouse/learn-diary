#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll sol(string s)
{
    int lis = 0; // 0,2,4....ABABAB和BABABA
    ll res = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
        {
            res += abs(lis - i);
            lis += 2;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    t = s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'A')
            t[i] = 'B';
        else
            t[i] = 'A';
    }
    cout << min(sol(s), sol(t)) << "\n";
    return 0;
}