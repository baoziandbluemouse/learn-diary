#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string x;
    cin >> x;
    stack<string> st;
    st.push(x);
    cout << st.top() << "\n";
    return 0;
}