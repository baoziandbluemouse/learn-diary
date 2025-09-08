#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 205
char s1[MAX];
char s2[MAX];
int a[MAX];
int b[MAX];
int c[MAX];

int main(void)
{
    int lena, lenb;
    int i = 0;
    scanf("%200s", s1);
    scanf("%200s", s2);
    lena = strlen(s1);
    lenb = strlen(s2);

    for (i = 0; i < lena; i++)
    {
        a[lena - i] = s1[i] - '0';
    }
    for (i = 0; i < lenb; i++)
    {
        b[lenb - i] = s2[i] - '0';
    }

    int lenc = lena + lenb;

    for (i = 1; i <= lenb; i++)
    {
        for (int j = 1; j <= lena; j++)
        {
            c[i + j - 1] += a[j] * b[i];
            c[i + j] += c[i + j - 1] / 10;
            c[i + j - 1] %= 10;
        }
    }

    if (c[lenc] == 0 && lenc > 0)
    {
        lenc--;
    }

    for (i = lenc; i > 0; i--)
    {
        printf("%d", c[i]);
    }

    printf("\n");
    return 0;
}
