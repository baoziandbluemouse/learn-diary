#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int ans = 0;
    int l = 0;
    map<char, int> mp;
    for (int r = 0; r < str.size(); r++)
    {
        mp[str[r]]++;
        while (mp[str[r]] > 1)
        {
            mp[str[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << "\n";
    return 0;
}