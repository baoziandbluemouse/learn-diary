#include <iostream>
using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x - last > s)
        {
            cout << "No\n";
            return 0;
        }
        last = x;
    }
    cout << "Yes\n";
    return 0;
}