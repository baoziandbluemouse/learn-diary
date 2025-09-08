#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll arr[5];
ll sum;
int main(void)
{
    ll t;
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld", &n, &arr[1], &arr[2], &arr[3]);
        sum = arr[1] + arr[2] + arr[3];
        ll days1 = 0;
        ll rest = 0;
        days1 = (n / sum) * 3;
        rest = n % sum;
        if (rest == 0)
        {
            printf("%lld\n", days1);
            continue;
        }
        for (int i = 1; i <= 3; i++)
        {
            rest -= arr[i];
            days1++;
            if (rest <= 0)
            {
                printf("%lld\n", days1);
                break;
            }
        }
    }
    return 0;
}