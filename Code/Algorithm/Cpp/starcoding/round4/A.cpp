#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int i = 0;
    for (auto &x : a)
    {
        if (x != i)
        {
            cout << i << "\n";
            return 0;
        }
        i++;
    }
    cout << i << "\n";
    return 0;
}