#include <bits/stdc++.h>
using namespace std;
vector<char> charindex = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int main()
{
    int x, k;
    cin >> x >> k;
    int max_len = to_string(k).size() + to_string(x).size() + 1;
    while (x > 0)
    {
        int fs_len = to_string(k).size() + to_string(x).size() + 1;
        int sc_len = to_string(x).size();
        cout << string(max_len - fs_len, ' ') << k << '|' << x << ' ' << charindex[x % k] << '\n';
        cout << string(max_len - sc_len, ' ');
        cout << string(to_string(x).size(), '-') << '\n';
        x /= k;
    }
    cout << string(max_len - 1, ' ') << 0 << '\n';
    return 0;
}