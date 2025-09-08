#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int cnt = 0;

    while ((ch = getchar()) != '\n')
    {
        if (isdigit(ch))
        {
            cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}