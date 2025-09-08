#include <stdio.h>

int main(void)
{
    int n, j;
    scanf("%d%d", &n, &j);
    int cnt = 0;
    while (1)
    {

        if (n >= j)
        {
            printf("%d\n", cnt);
            return 0;
        }
        else
        {
            n += 10;
            cnt++;
        }
    }
}