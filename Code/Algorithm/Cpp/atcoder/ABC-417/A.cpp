#include <iostream>
using namespace std;

int main()
{
    int n, st, sc;
    cin >> n >> st >> sc;
    string s;
    cin >> s;
    for (int i = st; i < s.size() - sc; i++)
    {
        cout << s[i];
    }
    cout << "\n";
    return 0;
}