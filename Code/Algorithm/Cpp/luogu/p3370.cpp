#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1e4 + 9;
ull base = 131;
ull a[N];
ull s[N];

ull hash_h(string st)
{
    int len = st.size();
    ull ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = ans * base + (ull)st[i];
        // 枚举了字符串的每一位，将每一位与base相乘，转为base进制
        // 加(ull)是为了防止爆栈搞出一个负数，(ull)是无符号的
        // 这里不取模，让他自然溢出,定义为ull的数在超过2^32的时候会自然溢出
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string st;
    for (int i = 1; i <= n; i++)
    {
        cin >> st;
        a[i] = hash_h(st);
    }
    sort(a + 1, a + 1 + n);
    ull ans = 1; // 一定至少有一个
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i + 1])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}
