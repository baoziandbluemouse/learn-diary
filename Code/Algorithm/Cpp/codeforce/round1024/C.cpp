#include <iostream>
#include <vector>
using namespace std;

void magical_spiral(int n)
{
    vector<vector<int>> arr(n, vector<int>(n, -1));

    int x, y;
    if (n % 2 == 0)
    {
        x = n / 2 - 1;
        y = n / 2 - 1;
    }
    else
    {
        x = n / 2;
        y = n / 2;
    }

    arr[x][y] = 0;
    int value = 1, step = 1;

    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (value < n * n)
    {
        for (int d = 0; d < 4; d++)
        {
            int steps = step;

            step += d % 2;
            int dx = dir[d][0];
            int dy = dir[d][1];

            for (int i = 0; i < steps; i++)
            {
                x += dx;
                y += dy;

                if (0 <= x && x < n && 0 <= y && y < n && arr[x][y] == -1)
                {
                    arr[x][y] = value;
                    value++;
                }
                if (value >= n * n)
                {
                    break;
                }
            }

            if (value >= n * n)
            {
                break;
            }
        }
    }

    for (const auto &row : arr)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        magical_spiral(n);
    }

    return 0;
}