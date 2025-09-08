#include <string>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}