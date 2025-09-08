#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<int> v(n + 1);
    for (int i = 1; i < n; i++)
    {
        v[i] = v[i - 1];
        if (str[i] == str[i - 1])
        {
            v[i]++;
        }
    }
    int l = 0, r = 0;
    while (q--)
    {
        cin >> l >> r;
        cout << v[r - 1] - v[l - 1] << "\n";
    }
    return 0;
}