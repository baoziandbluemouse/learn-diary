#include <iostream>
using namespace std;
int tx[4][3] = {
    {-1, -2, -3}, // 北
    {0, 0, 0},    // 西
    {1, 2, 3},    // 南
    {0, 0, 0},    // 东
};
int ty[4][3] = {
    {0, 0, 0},
    {-1, -2, -3},
    {0, 0, 0},
    {1, 2, 3},
};
int n, m, fx, fy;
int map[55][55];
int f[1000005][5]; // 1记录x，2记录y，3记录方向,0指向父对象,4记录时间；
void bfs();
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) // 读入地图；
            cin >> map[i][j];
    char c;
    cin >> f[1][1] >> f[1][2]; // 起始位置 ；
    map[f[1][1]][f[1][2]] = 2; // 注意：1为障碍物，2表示机器人来过；
    cin >> fx >> fy;           // 终点；
    cin >> c;
    if (f[1][1] == fx && f[1][2] == fy)
    { // 这是一个坑点；当终点与起始位置重合的时候；
        cout << 0;
        return 0;
    }
    if (c == 'N')
        f[1][3] = 0; // 初始化方向；
    if (c == 'W')
        f[1][3] = 1;
    if (c == 'S')
        f[1][3] = 2;
    if (c == 'E')
        f[1][3] = 3;
    bfs();
    return 0;
}
void bfs()
{
    int head = 0, tail = 1;
    while (head < tail)
    {
        head++;
        int i = 0;
        for (i = 0; i <= 2; i++)
        { // 3种移动情况；从前进1步开始；
            int xx = f[head][1] + tx[f[head][3]][i];
            int yy = f[head][2] + ty[f[head][3]][i];
            if (map[xx + 1][yy] == 1 || map[xx][yy + 1] == 1 || map[xx + 1][yy + 1] == 1 || map[xx][yy] == 1)
                break; // 如果前进更小的步数都会遇到障碍，那大步数就不需要加入队列了；这样可以解决跳过障碍物的情况；
            if (xx >= 1 && xx < n && yy >= 1 && yy < m && map[xx][yy] == 0)
            {                    // 边界
                map[xx][yy] = 2; // 设置为来过；
                tail++;
                f[tail][1] = xx;
                f[tail][2] = yy;
                f[tail][3] = f[head][3];     // 方向不变；
                f[tail][4] = f[head][4] + 1; // 时间+1；
                if (xx == fx && yy == fy)
                {
                    cout << f[tail][4]; // 到达终点；
                    return;
                }
            }
        }
        if (f[head][0] != 2)
        { // 要遍历4个方向要旋转2次；但这样有个问题：这样每个方向都会加入队列2次，但如果不这样就需要一个3维数组来记录每个方向是否来过；这两种方法都可取；所以我选择了代码较简洁的一种；
            for (int j = 1; j <= 3; j++)
            { // 旋转，当为1的时候向左转，为3的时候向右转；
                if (j != 2)
                {
                    tail++;
                    f[tail][1] = f[head][1]; // 位置不变；
                    f[tail][2] = f[head][2];
                    f[tail][3] = (f[head][3] + j) % 4; // 改变方向；
                    f[tail][4] = f[head][4] + 1;       // 时间+1；
                    f[tail][0] = f[head][0] + 1;       // 标记此元素由旋转得来；当此元素是由旋转过一次的元素得来时，此元素将不再进行旋转；此时f[.][0]==2;
                }
            }
        }
    }
    cout << -1; // 队列为空了，无法抵达；
}