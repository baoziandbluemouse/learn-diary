#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (q--)
    {
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else
        {
            if (pq.size())
            {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    return 0;
}