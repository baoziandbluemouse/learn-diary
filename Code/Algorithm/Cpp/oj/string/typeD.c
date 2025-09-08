#include <stdio.h>
#include <string.h>
#define MAX 150

int main(void)
{
    char str[MAX];
    char str_copy[MAX];
    int i, len = 0;
    int j = 1;

    gets(str);

    len = strlen(str);

    while (i < len & j < len)
    {
        str_copy[i] = str[i] + str[j];
        i++;
        j++;
        if (j == len)
        {
            j = 0;
        }
    }

    for (i = 0; i < len; i++)
    {
        printf("%c", str_copy[i]);
    }

    return 0;
}