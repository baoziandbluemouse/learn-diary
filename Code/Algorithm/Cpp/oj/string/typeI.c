#include <stdio.h>
#include <string.h>
#define MAX 1200
char str[MAX];

int main(void)
{
    int i = 0;
    int len = 0;
    int first = 1;

    fgets(str, MAX, stdin);

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }
        i++;
    }

    for (i = 0; i <= strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            if (!first & len != 0)
            {
                printf(",");
            }
            if (len != 0)
            {
                printf("%d", len);
                len = 0;
                first = 0;
            }
        }
        else
        {
            len++;
        }
    }
    return 0;
}