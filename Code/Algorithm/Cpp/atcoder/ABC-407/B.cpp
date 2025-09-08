#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int cnt = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (abs(i - j) < y && (i + j) < x)
            {
                cnt++;
            }
        }
    }
    printf("%.10lf", 1 - 1.0 * cnt / 36);
    return 0;
}