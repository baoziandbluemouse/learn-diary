#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
typedef long long ll;

vector<int> X;
int a[N];

int getnum(int x)
{
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}

void solve()
{

    int n;
    cin >> n;
    memset(a, 0, sizeof((n + 1) * sizeof(int)));
    X.clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        X.push_back(a[i]);
    }
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 1; i <= n; i++)
    {
        cout << getnum(a[i]) << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}