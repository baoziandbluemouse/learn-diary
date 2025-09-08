#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int m;
    cin >> m;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (op == "remove")
        {
            if (!pq.empty())
            {
                pq.pop();
            }
            else
            {
                cout << "empty" << "\n";
            }
        }
        else if (op == "min")
        {
            if (!pq.empty())
            {
                cout << pq.top() << "\n";
            }
            else
            {
                cout << "empty" << "\n";
            }
        }
        else if (op == "print")
        {
            int k;
            cin >> k;
            while (k--)
            {
                cout << pq.top() << " ";
                pq.pop();
            }
            cout << "\n";
        }
    }
    return 0;
}