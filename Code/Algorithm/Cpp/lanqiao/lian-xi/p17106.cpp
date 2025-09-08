#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    deque<int> q1, q2;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        q1.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q2.push_back(x);
    }
    int ans = 0;
    while (!q1.empty() && !q2.empty())
    {
        if (q1.front() == q2.front())
        {
            q1.pop_front();
            q2.pop_front();
        }
        else if (q1.front() < q2.front())
        {
            q1[1] += q1[0];
            q1.pop_front();
            ans++;
        }
        else if (q1.front() > q2.front())
        {
            q2[1] += q2[0];
            q2.pop_front();
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}