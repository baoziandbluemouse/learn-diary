#include <iostream>
#include <algorithm>
#define MAX 30010
using namespace std;
int price[MAX];

int main(void)
{
    int n, w, i = 1, cnt = 0;
    cin >> w;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    sort(price + 1, price + n + 1);
    int *begin = &price[1], *end = &price[n];
    while (1)
    {
        if (begin > end)
        {
            cout << cnt << "\n";
            return 0;
        }
        if (begin == end)
        {
            cnt++;
            cout << cnt << "\n";
            return 0;
        }
        if (*begin + *end <= w)
        {
            cnt++;
            begin++;
            end--;
        }
        else
        {
            cnt++;
            end--;
        }
    }
}