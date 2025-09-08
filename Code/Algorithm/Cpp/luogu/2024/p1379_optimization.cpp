#include <bits/stdc++.h>
using namespace std;
string end1 = "123804765";
unordered_map<string, int> dist;
unordered_map<string, int> st; // 1代表起点标记，2代表终点标记
queue<string> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(string start);

int main(void)
{
    string start;
    cin >> start;
    int res = 0;
    if (start == end1)
    {
        cout << 0 << "\n";
        return 0;
    }
    res = bfs(start);
    cout << res << "\n";
    return 0;
}

int bfs(string start)
{
    q.push(start);
    dist[start] = 0;
    st[start] = 1;
    q.push(end1);
    dist[end1] = 0;
    st[end1] = 2;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int flag = st[t];       // 取出当前状态的标记
        int distance = dist[t]; // 取出当前状态的距离
        int ta = t.find('0');
        int tx = ta / 3;
        int ty = ta % 3;
        for (int i = 0; i < 4; i++)
        {
            int c = tx + dx[i];
            int d = ty + dy[i];
            if (c < 0 || c >= 3 || d < 0 || d >= 3)
                continue;
            int temp = c * 3 + d;
            swap(t[ta], t[temp]);
            if (st[t] + flag == 3)
            {
                return dist[t] + distance + 1;
            }
            if (!dist.count(t))
            {
                dist[t] = distance + 1;
                st[t] = flag;
                q.push(t);
            }
            swap(t[ta], t[temp]);
        }
    }
    return 0;
}
