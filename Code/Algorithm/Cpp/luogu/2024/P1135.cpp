#include <bits/stdc++.h>
using namespace std; // 每层楼最多走一次取到的方案是最好的
#define MAX 250
typedef pair<int, int> PII;
int arr[MAX]; // 存储楼层能增加数字几
bool st[MAX]; // 存储楼层是否走过
queue<PII> q;
int bfs(int x);
int n, a, b;
int main(void)
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int res = bfs(a);
    cout << res << "\n";
}

int bfs(int x)
{
    q.push({x, 0});
    st[x] = true;
    int res = 0;
    if (x == b)
    {
        return 0;
    }
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        int tmp = t.first;
        int cnt = t.second;
        // 上层
        if (tmp + arr[tmp] <= n && !st[tmp + arr[tmp]])
        {
            if (tmp + arr[tmp] == b)
            {
                return cnt + 1;
            }
            q.push({tmp + arr[tmp], cnt + 1});
            st[tmp + arr[tmp]] = true;
        }
        // 下层
        if (tmp - arr[tmp] >= 1 && !st[tmp - arr[tmp]])
        {
            if (tmp - arr[tmp] == b)
            {
                return cnt + 1;
            }
            q.push({tmp - arr[tmp], cnt + 1});
            st[tmp - arr[tmp]] = true;
        }
    }
    return -1;
}