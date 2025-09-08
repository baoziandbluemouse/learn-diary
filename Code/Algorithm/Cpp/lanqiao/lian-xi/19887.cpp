#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int m;
    cin >> m;
    int top = 0;
    while (m--)
    {
        string op;
        cin >> op;
        if (op == "push")
        {
            int x;
            cin >> x;
            a[++top] = x;
        }
        else if (op == "pop")
        {
            if (top >= 1)
                top--;
        }
        else if (op == "empty")
        {
            if (top == 0)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        else if (op == "query")
        {
            if (top == 0)
                cout << "empty" << "\n";
            else
                cout << a[top] << "\n";
        }
    }
    return 0;
}