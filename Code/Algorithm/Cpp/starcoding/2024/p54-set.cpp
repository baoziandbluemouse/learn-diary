#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st.insert(x);
    }
    for (auto &i : st)
    {
        cout << i << " ";
    }
    return 0;
}
