#include <iostream>
using namespace std;
const int N = 510;
int a[N];
int prefix[N];
int main()
{
    for (int i = 1; i <= N; i++)
    {
        a[i] = a[i - 1] + i;
    }
    for (int i = 1; i <= N; i++)
    {
        prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = 490; i <= 500; i++)
    {
        if (prefix[i] >= 20230610)
        {
            cout << prefix[i] << "\t" << prefix[i - 1] << "\n";
            cout << i << "\t" << i - 1 << "\n";
            break;
        }
    }
    return 0;
}