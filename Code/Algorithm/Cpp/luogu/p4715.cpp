#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n = 1 << n;              // 相当于2的n次方
    queue<pair<int, int>> q; // 队列，first代表编号，second代表能力值
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push({i, x});
    }
    while (q.size() > 2) // 直到只剩下两个选手
    {
        pair<int, int> a = q.front();
        q.pop();
        pair<int, int> b = q.front();
        q.pop();
        if (a.second > b.second)
        {
            q.push(a);
        }
        else
        {
            q.push(b);
        }
    }

    pair<int, int> x, y; // 最后的冠亚军再判断一下就可以输出结果了
    x = q.front();
    q.pop();
    y = q.front();
    q.pop();

    if (x.second > y.second)
    {
        cout << y.first << "\n";
    }
    else
    {
        cout << x.first << "\n";
    }
    return 0;
}