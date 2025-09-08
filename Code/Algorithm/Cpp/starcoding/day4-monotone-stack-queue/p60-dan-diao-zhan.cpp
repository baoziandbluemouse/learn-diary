#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9;
int arr[N], l[N];

// int main(void)
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int n;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> arr[i];
//     }
//     memset(l, -1, sizeof(l));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = i; j >= 1 && l[i] == -1; j--)
//         {
//             if (arr[j] < arr[i])
//             {
//                 l[i] = arr[j];
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         cout << l[i] << " ";
//     }
//     return 0;
// }

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    stack<int> stk; // 栈内存放下标
    for (int i = 1; i <= n; i++)
    {
        while (stk.size() && arr[stk.top()] >= arr[i])
        {
            stk.pop();
        }

        if (stk.size())
        {
            // 栈非空
            l[i] = stk.top();
        }
        else
        {
            // 栈空
            l[i] = -1;
        }
        // 将当前元素下标push进去
        stk.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << (l[i] == -1 ? -1 : arr[l[i]]) << " ";
    }
    return 0;
}