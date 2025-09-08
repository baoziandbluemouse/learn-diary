#include <bits/stdc++.h>
using namespace std;
const int N = 92200229;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int x)
{
    int year = x / 10000;
    int mon = (x % 10000) / 100;
    int day = x % 100;
    if (day == 0 || mon == 0 || mon > 12)
    {
        return false;
    }
    if (mon != 2 && day > month[mon])
    {
        return false;
    }
    if (mon == 2)
    {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
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

bool ishuiwen(int x)
{
    string f = to_string(x);
    int len = f.size();
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (f[i] != f[j])
        {
            return false;
        }
    }
    return true;
}

bool isab(int x)
{
    if (ishuiwen(x))
    {
        string f = to_string(x);
        if (f[0] != f[2] || f[1] != f[3] || f[0] == f[1])
        {
            return false;
        }
        return true;
    }

    return false;
}

int main()
{

    int n;
    cin >> n;
    bool flag = false;
    for (int i = n + 1;; i++)
    {
        if (check(i))
        {
            if (ishuiwen(i) && flag == false)
            {
                cout << i << "\n";
                flag = true;
            }
            if (isab(i))
            {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}