#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 60

int main(void)
{
    char str[MAX];
    char str_reverse[MAX];
    int len = 0;
    int i = 0;

    scanf("%50s", str);
    len = strlen(str);

    for (i = 0; i < len; i++)
    {
        if (islower(str[i]))
        {
            if (str[i] >= 120)
            {
                str[i] = str[i] - 23;
            }
            else
            {
                str[i] = str[i] + 3;
            }
            continue;
        }
        if (isupper(str[i]))
        {
            if (str[i] >= 88)
            {
                str[i] = str[i] - 23;
            }
            else
            {
                str[i] = str[i] + 3;
            }
            continue;
        }
    }

    for (i = len - 1; i >= 0; i--)
    {
        str_reverse[len - i - 1] = str[i];
    }

    for (i = 0; i < len; i++)
    {
        if (islower(str_reverse[i]))
        {
            printf("%c", str_reverse[i] - 32);
        }
        if (isupper(str_reverse[i]))
        {
            printf("%c", str_reverse[i] + 32);
        }
    }
    printf("\n");

    return 0;
}