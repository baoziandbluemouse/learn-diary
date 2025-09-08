#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int len = n.length();
    bool flag = false;
    for (int i = 0; i < len - 1; i++)
    {
        if (n[i] == '9' && n[i + 1] == '9')
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}