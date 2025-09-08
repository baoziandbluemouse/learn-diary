#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m;
struct node
{
    int num;
    int val;
    bool operator<(const node &b) const
    {
        if (val != b.val)
        {
            return val > b.val;
        }
        else
        {
            return num < b.num;
        }
    }
};
node a[N];
string strs[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        a[i].num = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> strs[i];
    }
    for (int j = 0; j < m; j++)
    {
        int cnt_0 = 0, cnt_1 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (strs[i][j] == '0')
            {
                cnt_0++;
            }
            else
            {
                cnt_1++;
            }
        }
        if (cnt_0 == 0 || cnt_1 == 0)
        {
            for (int k = 1; k <= n; k++)
            {
                a[k].val++;
            }
        }
        if (cnt_0 > cnt_1)
        {
            for (int i = 1; i <= n; i++)
            {
                if (strs[i][j] == '1')
                {
                    a[i].val++;
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (strs[i][j] == '0')
                {
                    a[i].val++;
                }
            }
        }
    }
    sort(a + 1, a + n + 1);
    cout << a[1].num << " ";
    for (int i = 2; i <= n; i++)
    {
        if (a[1].val == a[i].val)
        {
            cout << a[i].num << " ";
        }
        else
        {
            continue;
        }
    }
    cout << "\n";
    return 0;
}