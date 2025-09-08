#include <bits/stdc++.h>
using namespace std;
void exercise(int N)
{
    cout << N;
    if (N < 3)
    {
        exercise(N + 1);
    }
    cout << N;
}
int main(void)
{
    exercise(1);
    return 0;
}