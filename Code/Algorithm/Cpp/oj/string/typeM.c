#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

void strlower(char *a)
{
    for (int i = 0; a[i]; i++)
    {
        if (isupper(a[i]))
            a[i] = tolower(a[i]);
    }
}

int main(void)
{
    char str1[11];
    char str2[1000001];
    char *p, *q;
    bool flag = false;
    int cnt = 0;
    int place = 0;

    gets(str1);
    gets(str2);

    strlower(str1);
    strlower(str2);

    int len = strlen(str1);

    p = str2;

    for (; q = strstr(p, str1);)
    {
        if (q != NULL && (q == str2 || *(q - 1) == ' ') && (*(q + len) == ' ' || *(q + len) == '\0'))
        {
            cnt++;
            if (flag == false)
            {
                flag = true;
                place = q - str2;
            }
        }
        p = q + len;
    }

    if (flag == true)
    {
        printf("%d %d\n", cnt, place);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
