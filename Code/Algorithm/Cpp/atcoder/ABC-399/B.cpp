#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 150;
int a[N];
struct node
{
    int rank;
    int val;
    bool operator<(const node &b) const
    {
        return (val == b.val) ? rank > b.rank : val > b.val;
    }
};
vector<node> arr;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        arr.push_back({i, x});
    }
    sort(arr.begin(), arr.end());
    int r = 1;
    int p = 0;
    int cnt = 0;
    for (auto &i : arr)
    {
        if (i.val != p)
        {
            p = i.val;
            r += cnt;
            cnt = 0;
        }
        cnt++;
        a[i.rank] = r;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << "\n";
    }
    return 0;
}