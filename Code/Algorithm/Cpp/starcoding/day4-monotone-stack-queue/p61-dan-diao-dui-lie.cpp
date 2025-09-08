#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int a[N];

int main(void)
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    deque<int> dq;

    // 求最大
    for (int i = 1; i <= n; i++)
    {
        // 以i为右端点，大小为k的区间，[i-k+1,i]
        // 队头合法性
        while (dq.size() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        // 队尾优越性
        while (dq.size() && a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k)
        {
            cout << a[dq.front()] << " ";
        }
    }
    cout << "\n";

    dq = deque<int>(); // 清空

    // 求最小
    for (int i = 1; i <= n; i++)
    {
        // 以i为右端点，大小为k的区间，[i-k+1,i]
        // 队头合法性
        while (dq.size() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        // 队尾优越性
        while (dq.size() && a[dq.back()] >= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);

        if (i >= k)
        {
            cout << a[dq.front()] << " ";
        }
    }
    cout << "\n";
    return 0;
}