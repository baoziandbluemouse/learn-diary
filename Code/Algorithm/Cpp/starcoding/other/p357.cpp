#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    deque<string> s;
    while (n--)
    {
        string op1;
        cin >> op1;
        if (op1 == "f")
        {
            string op2;
            cin >> op2;
            if (op2 == "w")
            {
                string op3;
                cin >> op3;
                s.push_front(op3);
            }
            else
            {
                if (s.size())
                {
                    s.pop_front();
                }
            }
        }
        else
        {
            string op2;
            cin >> op2;
            if (op2 == "w")
            {
                string op3;
                cin >> op3;
                s.push_back(op3);
            }
            else
            {
                if (s.size())
                {
                    s.pop_back();
                }
            }
        }
    }
    if (s.size() == 0)
    {
        cout << "#\n";
    }
    else
    {
        while (s.size())
        {
            cout << s.front();
            s.pop_front();
        }
    }
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}