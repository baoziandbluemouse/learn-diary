#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s = "";
    string ans;
    cin >> n;
    if (n == 1)
    {
        cout << "=" << "\n";
        return 0;
    }
    else if (n == 2)
    {
        cout << "==" << "\n";
        return 0;
    }
    if (n & 1)
    {
        int cnt = n / 2;
        s.append(cnt, '-');
        ans = s + '=' + s;
    }
    else
    {
        int cnt = (n / 2) - 1;
        s.append(cnt, '-');
        ans = s + "==" + s;
    }
    cout << ans << "\n";
    return 0;
}