#include <iostream>
#include <string>
using namespace std;
string t;
string u;

bool check(int st)
{
    int n = u.size();
    int s = t.size();
    for (int i = 0; i < n; i++)
    {
        if (st + i >= s)
        {
            return false;
        }
        if (t[st + i] != '?' && t[st + i] != u[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> t;
    cin >> u;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == '?' || t[i] == u[0])
        {
            if (check(i))
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}