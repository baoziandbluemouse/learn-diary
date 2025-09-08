#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    deque<int> dq; // 单调队列
    // 计算窗口的最小值
    for (int i = 1; i <= n; i++)
    {
        // 队头合法
        while (dq.size() && dq.front() <= i - k)
            dq.pop_front();
        // 队尾优越性
        while (dq.size() && a[i] <= a[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        // 输出答案
        if (i >= k)
            cout << a[dq.front()] << " ";
    }
    cout << "\n";
    // 计算窗口最大值
    dq.clear();
    for (int i = 1; i <= n; i++)
    {
        // 队头合法性
        while (dq.size() && dq.front() <= i - k)
            dq.pop_front(); // 出队头
        // 队尾优越性，保证单调递减
        while (dq.size() && a[i] >= a[dq.back()])
            dq.pop_back(); // 出队尾
        dq.push_back(i);
        // 输出答案
        if (i >= k)
            cout << a[dq.front()] << " ";
    }
    cout << "\n";
    return 0;
}