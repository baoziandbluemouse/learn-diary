#include <bits/stdc++.h>
using namespace std;
void Swap(int &a, int &b)
{
    if (a != b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

// void test()
// {
//     string s = "2015Äê10ÔÂ21ÈÕ";

//     int year = stoi(s.substr(0, year_end));
//     int month = stoi(s.substr(year_end + 1));
//     int day = stoi(s.substr(month_end + 1));

//     cout << year << "\t" << month << "\t" << day << endl;
// }

int main(void)
{
    // int a = 10, b = 20;
    // Swap(a, b);
    // cout << a << " " << b << endl;

    return 0;
}