#include <iostream>
using namespace std;

int main(void)
{
    int x, y;
    cin >> x >> y;
    int k = 0;
    while ((k = (y % x)))
    {
        y = x;
        x = k;
    }
    cout << x << "\n";
    return 0;
}