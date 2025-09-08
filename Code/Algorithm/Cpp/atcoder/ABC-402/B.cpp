#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int q[N], front, back;

void solve()
{
    int op;
    cin >> op;
    if (op == 1)
    {
        int x;
        cin >> x;
        q[back++] = x;
    }
    else
    {
        cout << q[front++] << "\n";
    }
}

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}