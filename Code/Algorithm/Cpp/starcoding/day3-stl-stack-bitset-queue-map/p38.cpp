#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;

int arr[N];
stack<int> stk;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        stk.push(arr[i]);
        while (stk.size() && stk.top() == cnt)
        {
            stk.pop();
            cnt++;
        }
    }
    if (stk.size())
    {
        cout << "No" << '\n';
    }
    else
    {
        cout << "Yes" << '\n';
    }
    return 0;
}