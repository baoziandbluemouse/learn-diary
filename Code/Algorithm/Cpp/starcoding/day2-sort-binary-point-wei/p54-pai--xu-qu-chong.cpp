#include <bits/stdc++.h> //运用排序，动态数组，unique实现去重
using namespace std;     // 另一种去重办法使用set
vector<int> a;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end()); // unique函数实际是把重复的数移到后面去了
    // 最终函数会返回不重复的数的最后一个位置的后一个位置(迭代器),然后我们再用erase函数删除后面的数即可
    // unique函数只能把相邻的重复数删除，所以我们需要先排序
    // unique返回的是迭代器
    for (auto &i : a)
        cout << i << '\n';
    return 0;
}
