#include <iostream>
#include <string>
using namespace std;
const int N = 110;
int a[N];

void solve()
{
    int n;
    cin >> n;
    int j = n;
    int m = 1;
    string s;
    cin >> s;
    s = " " + s;
    int len = s.size() - 1;
    for (int i = len; i >= 1; i--)
    {
        if (s[i] == '>')
        {
            a[i + 1] = j;
            j--;
        }
        else if (s[i] == '<')
        {
            a[i + 1] = m;
            m++;
        }
    }
    a[1] = m;
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}