#include <bits/stdc++.h>
using namespace std;
const int NR = 2e5 + 10;
int n, k, cnt;
char s[NR], t[NR];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        t[i] = s[i];
    }
    // 判断相邻是否为o
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'o')
            t[i] = '.';
        if (s[i + 1] == 'o')
            t[i] = '.';
        if (t[i] == 'o')
        {
            cnt++;
        }
    }
    // cnt=k时有唯一解
    if (cnt == k)
    {
        for (int i = 1; i <= n; i++)
        {
            if (t[i] == '?')
            {
                t[i] = '.';
            }
            cout << t[i];
        }
        return 0;
    }
    int len = 0; // 统计？区间长度
    for (int i = 1; i <= n + 1; i++)
    {
        if (t[i] == '?')
        {
            len++;
        }
        else
        {
            cnt += (len + 1) / 2; // 向上取整
            len = 0;
        }
    }
    len = 0;
    if (cnt == k)
    {
        for (int i = 1; i <= n + 1; i++)
        {
            if (t[i] == '?')
            {
                len++;
            }
            else
            {

                if (len % 2 == 1)
                {
                    int p = 0;
                    for (int j = i - 1; j >= i - len; j--)
                    {
                        p++;
                        if (p % 2)
                            t[j] = 'o';
                        else
                            t[j] = '.';
                    }
                }
                len = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << t[i];
    }
    return 0;
}