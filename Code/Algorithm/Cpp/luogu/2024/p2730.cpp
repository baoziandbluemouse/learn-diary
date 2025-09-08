#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> dist;               // 存到当前状态需要几步
unordered_map<string, pair<char, string>> pre; // 存从哪一个状态转移过来，而且要存A还是B还是C操作
queue<string> q;
char g[10][10];
// 把一维字符串转为二维数组
void set1(string t)
{
    for (int i = 0; i < 4; i++)
    {
        g[0][i] = t[i];
    }
    for (int i = 3, j = 4; i >= 0; i--, j++)
    {
        g[1][i] = t[j];
    }
}

// 把二维数组转换为一维字符串
string get1()
{
    string res;
    for (int i = 0; i < 4; i++)
    {
        res += g[0][i];
    }
    for (int i = 3; i >= 0; i--)
    {
        res += g[1][i];
    }
    return res;
}

int bfs(string start, string end1);
string move0(string t);
string move1(string t);
string move2(string t);

int main(void)
{
    int x;
    string start, end1;
    for (int i = 1; i <= 8; i++)
    {
        cin >> x;
        end1 += x + '0';
    }
    for (int i = 1; i <= 8; i++)
    {
        start += i + '0';
    }
    int res = bfs(start, end1);
    cout << res << "\n";

    string res2;
    while (end1 != start)
    {
        res2 += pre[end1].first; // 这样得出的是逆序的操作
        end1 = pre[end1].second;
    }

    reverse(res2.begin(), res2.end()); // 反转
    if (res2.size())
    {
        cout << res2 << "\n";
    }
    return 0;
}

int bfs(string start, string end1)
{
    q.push(start);
    dist[start] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        if (t == end1) // 假如基础状态就是目标状态
        {
            return dist[end1];
        }
        string m[3];
        m[0] = move0(t);
        m[1] = move1(t);
        m[2] = move2(t);

        for (int i = 0; i < 3; i++)
        {
            string s = m[i];
            if (!dist.count(s))
            {
                dist[s] = dist[t] + 1;
                pre[s] = {char(i + 'A'), t}; //(用哪个操作过来的，变换后的串)
                if (s == end1)
                {
                    return dist[end1];
                }
                q.push(s);
            }
        }
    }
    return -1;
}

string move0(string t) // A变换
{
    set1(t);
    for (int i = 0; i < 4; i++)
    {
        swap(g[0][i], g[1][i]);
    }
    return get1();
}

string move1(string t) // B变换
{
    set1(t);
    // 通过交换实现
    for (int i = 3; i >= 1; i--)
    {
        swap(g[0][i], g[0][i - 1]);
        swap(g[1][i], g[1][i - 1]);
    }
    return get1();
}

string move2(string t) // C变换
{
    set1(t);
    // 把中间四个数中左上角的数存起来，然后直接转一圈
    char temp = g[0][1];
    g[0][1] = g[1][1];
    g[1][1] = g[1][2];
    g[1][2] = g[0][2];
    g[0][2] = temp;
    return get1();
}