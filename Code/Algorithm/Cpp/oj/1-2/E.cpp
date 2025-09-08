#include <iostream>
#include <cstdio>
#include <cstring>
#define N 10
char str[N];
char str_new[N];                // 存答案
bool sta[N];                    // 记录是否使用过
void dfs(int x, const int len); // x为当前枚举到哪个位置
int main(void)
{
    scanf("%6s", str);
    int len = strlen(str);
    dfs(0, len);
    return 0;
}

void dfs(int x, const int len)
{
    if (x == len)
    {
        printf("%s\n", str_new);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!sta[i])
        {
            sta[i] = true;
            str_new[x] = str[i];
            dfs(x + 1, len);
            sta[i] = false;
            str_new[x] = '0';
        }
    }
}