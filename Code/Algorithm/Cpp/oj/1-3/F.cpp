#include <iostream>
#define MAX 100010
using namespace std;
int arr[MAX], n, ans;

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int base = 0;
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] >= base)
        {
            base = arr[i];
        }
        else
        {
            ans += (base - arr[i]);
            base = arr[i];
        }
    }
    cout << ans << "\n";
    return 0;
}