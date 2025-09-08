#include <bits/stdc++.h>
using namespace std;
void solve(int n, int m);
int main(void)
{
    int t;
    cin >> t;
    while (t--)
    {
        int n = 0, m = 0;
        cin >> n >> m;
        solve(n, m);
    }
}

void solve(int n, int m)
{
    int x = 0;
    queue<int> lead;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        lead.push(x);
    }
    while (lead.size() > 1)
    {
        int temp = 0;
        for (int i = 1; i < m; i++)
        {
            temp = lead.front();
            lead.push(temp);
            lead.pop();
        }
        lead.pop();
    }
    cout << lead.front() << "\n";
}