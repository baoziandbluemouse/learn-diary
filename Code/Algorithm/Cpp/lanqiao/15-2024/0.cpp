#include <bits/stdc++.h>
using namespace std;
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[] = {13, 1, 2, 3, 5, 4, 4, 2, 2, 2};
string tobe_string(int x)
{
    string s;
    while (x)
    {
        s = char(x % 10 + '0') + s;
        x /= 10;
    }
    return s;
}
bool check(int x)
{
    int year = x / 10000;
    int month = (x % 10000) / 100;
    int day = x % 100;
    // 判断月合法
    if (month == 0 || month > 12)
    {
        return false;
    }
    // 判断天合法（闰年2月29）
    if (month != 2)
    {
        if (day == 0 || day > mon[month])
        {
            return false;
        }
    }
    else
    {
        if (day == 0)
        {
            return false;
        }
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        {
            if (day > 29)
            {
                return false;
            }
        }
        else
        {
            if (day > 28)
            {
                return false;
            }
        }
    }
    return true;
}
bool isbasketball(int x)
{
    string str = tobe_string(x);
    int len = str.length();
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        sum += a[str[i] - '0'];
    }
    return (sum > 50) ? true : false;
}
int main()
{
    int n = 20000101;
    int ans = 0;
    for (int i = n; i <= 20240413; i++)
    {
        if (check(i))
        {
            if (isbasketball(i))
            {
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}