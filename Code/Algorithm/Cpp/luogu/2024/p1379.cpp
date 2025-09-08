#include <bits/stdc++.h>
using namespace std;

string end1 = "123804765";       // 状态压缩
unordered_map<string, int> dist; // 哈希表
queue<string> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1}; // 上下左右四个方向

int bfs(string start);

int main()
{
    string start;
    cin >> start;

    int res = bfs(start);
    cout << res << "\n";
    return 0;
}

int bfs(string start)
{
    q.push(start);
    dist[start] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        if (t == end1)
        {
            return dist[t];
        }

        int distance = dist[t]; // 取出当前状态的距离

        // 一维数组下标转换为二维数组下标（找到0的位置-->一维数组下标-->二维数组下标）
        int ta = t.find('0');
        int tx = ta / 3; // 实现字符串转换为3*3的矩阵（这个矩阵是从(0,0)开始的)
        int ty = ta % 3; // tx第几行，ty第几列
        for (int i = 0; i < 4; i++)
        {
            int a = tx + dx[i];
            int b = ty + dy[i];
            if (a < 0 || a >= 3 || b < 0 || b >= 3)
                continue;
            int temp = a * 3 + b; // 实现二维数组下标转换为一维数组下标
            swap(t[ta], t[temp]);
            // 如果这个状态没有出现过，则加入队列，并计算距离
            if (!dist.count(t)) // count函数 看map中有没有key值为t的元素，如果有则返回1，没有则返回0
            {
                dist[t] = distance + 1;
                q.push(t);
            }
            swap(t[ta], t[temp]); // 恢复现场,为下个方向做准备
        }
    }
    return -1;
}