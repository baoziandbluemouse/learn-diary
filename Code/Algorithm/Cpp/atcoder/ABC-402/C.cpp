#include <iostream>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int a[N]; // a是菜，b是原料
vector<vector<int>> b(N, vector<int>());
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        a[i] = k;
        for (int j = 1; j <= k; j++)
        {
            int x;
            cin >> x;
            b[x].push_back(i);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (auto &i : b[x])
        {
            a[i]--;
            if (a[i] == 0)
            {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}