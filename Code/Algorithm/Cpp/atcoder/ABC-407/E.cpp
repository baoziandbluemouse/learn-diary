#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, a;

void sol()
{
    cin >> n;
    ll ans = 0;
    priority_queue<int> q;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a;
        q.push(a); // 大根堆处理
        if (i % 2) // 奇数次时进行括号处理，优先将队列中的最大值作为左括号，其余便为右括号
        {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans << "\n";
    return;
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        sol();
    }
    return 0;
}