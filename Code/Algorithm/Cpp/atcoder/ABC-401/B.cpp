#include <iostream>
#include <string>
using namespace std;
int cnt;
bool flag = false;
void solve()
{
    string s;
    cin >> s;
    if (s == "login")
    {
        flag = true;
    }
    else if (s == "logout")
    {
        flag = false;
    }
    else if (s == "private")
    {
        if (flag == false)
        {
            cnt++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    cout << cnt << "\n";
    return 0;
}