#include <bits/stdc++.h>
using namespace std;
const int N = 30; // 接龙可以先预处理

int n;
string words[N];                // 存储单词
int used[N];                    // 每个单词可以使用两次
int g[N][N];                    // g[i][j]存第i个单词是否能接到第j个单词后面,g[i][j]存重合长度
void dfs(string dragon, int x); // x代表当前接龙的是哪个单词
int res = 0;
int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    char start;
    cin >> start;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            string a = words[i], b = words[j]; // 枚举所有的单词对
            for (int k = 1; k < min(a.size(), b.size()); k++)
            {
                if (a.substr(a.size() - k, k) == b.substr(0, k)) // 枚举单词a的后缀和单词b的前缀，看是否能重合
                {
                    g[i][j] = k; // 单词a的后缀和单词b的前缀重合长度为k
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (words[i][0] == start)
        {
            dfs(words[i], i);
        }
    }
    cout << res << "\n";
    return 0;
}

void dfs(string dragon, int x)
{
    res = max(res, (int)dragon.size());
    used[x]++;
    for (int i = 0; i < n; i++)
    {
        if (g[x][i] && used[i] < 2)
        {
            dfs(dragon + words[i].substr(g[x][i]), i);
        }
    }
    used[x]--;
}