#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    double ans1 = n / 2.5;
    int ans2 = n * 10 / 25;
    if (ans1 != ans2)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
    }
    return 0;
}