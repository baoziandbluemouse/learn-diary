#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int q;
    ll sum = 0;
    priority_queue<ll> pq; // 默认是大根堆
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            ll x;
            cin >> x;
            pq.push(x);
            sum += x;
        }
        if (n == 2)
        {
            if (pq.size())
            {
                sum -= pq.top();
                pq.pop();
            }
        }
    }

    cout << sum << '\n';
    return 0;
}