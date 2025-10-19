#include <bits/stdc++.h>
using namespace std;
const int N = 8e5 + 10;
int pre[N];

void solve()
{
    int q;
    cin >> q;
    int len = 0;
    multiset<int> st;

    while (q--)
    {
        int op;
        char c;
        cin >> op;
        if (op == 1)
        {
            len++;
            cin >> c;
            if (c == '(')
            {
                pre[len] = pre[len - 1] + 1;
            }
            else
            {
                pre[len] = pre[len - 1] - 1;
            }
            st.insert(pre[len]);
        }
        else
        {
            st.erase(st.find(pre[len]));
            len--;
        }
        if (*st.begin() >= 0 && pre[len] == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}