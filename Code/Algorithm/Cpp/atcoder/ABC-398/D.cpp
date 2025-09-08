#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int prex[N], prey[N];

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    s = " " + s; // 从1开始
    map<pair<int, int>, int> mp;
    for (int i = 1; i < s.size(); i++) // 预处理偏移量前缀和
    {
        prex[i] = prex[i - 1];
        prey[i] = prey[i - 1];
        if (s[i] == 'N')
            prex[i]--;
        else if (s[i] == 'S')
            prex[i]++;
        else if (s[i] == 'E')
            prey[i]++;
        else if (s[i] == 'W')
            prey[i]--;
    }
    string ans;
    mp[{0, 0}] = 1;
    for (int i = 1; i <= n; i++)
    {
        int tr = prex[i] - r; // 得出起点
        int tc = prey[i] - c;
        if (mp.count({tr, tc})) // 看map中有没有
            ans += '1';
        else
            ans += '0';
        mp[{prex[i], prey[i]}]++; // 把起点加入map，假如t=1，我们就加入第二个烟的起点prex[2-1].prey[2-1];
    }
    cout << ans << "\n";
    return 0;
}