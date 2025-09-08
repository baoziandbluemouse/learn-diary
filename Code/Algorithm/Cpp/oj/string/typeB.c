#include <stdio.h>
#include <string.h>

#define STLEN 100100
int main(void)
{
    char s[STLEN];
    int a[26] = {0};
    int i = 0;

    fgets(s, STLEN, stdin);

    int len = strlen(s);

    for (i = 0; i < len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            a[s[i] - 'a']++;
        }
    }

    for (i = 0; i < len; i++)
    {
        if (a[s[i] - 'a'] == 1)
        {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("no\n");
    return 0;
}