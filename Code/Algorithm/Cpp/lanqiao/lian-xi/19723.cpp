#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 2e3 + 10;
int a[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string op;
    while (cin >> op)
    {
        if (op == "add")
        {
            int x;
            cin >> x;
            a[0]++;
        }
        else if (op == "sync")
        {
            int x;
            cin >> x;
            if (a[x] < a[0])
            {
                a[x]++;
            }
        }
        else
        {
            int minn = 1e9;
            for (int i = 0; i < n; i++)
            {
                minn = min(minn, a[i]);
            }
            cout << minn << "\n";
        }
    }
    return 0;
}