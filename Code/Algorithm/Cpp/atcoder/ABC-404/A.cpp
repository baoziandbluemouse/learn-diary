#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]] = 1;
    }
    int end = 'z' - 'a';
    for (int i = 0; i <= end; i++)
    {
        if (!mp.count((char)('a' + i)))
        {
            cout << (char)('a' + i) << "\n";
            break;
        }
    }
    return 0;
}
