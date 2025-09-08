#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> arr;

int main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        if (n == 2)
        {
            if (arr.size())
            {
                sort(arr.begin(), arr.end());
                arr.pop_back();
            }
        }
    }
    ll sum = 0;
    for (auto &i : arr)
    {
        sum += i;
    }
    cout << sum << '\n';

    return 0;
}