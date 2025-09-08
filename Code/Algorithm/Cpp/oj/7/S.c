#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 205
char s1[MAX];
char s2[MAX];
int a[MAX];
int b[MAX];
int c[MAX];

int max(int a, int b);

bool compare(char *s1, char *s2);

int main(void)
{
    int lena, lenb;
    int i = 0;
    bool flag = false;
    scanf("%200s", s1);
    scanf("%200s", s2);
    if (!compare(s1, s2)) // 如果s1<s2 交换s1和s2
    {
        flag = true;
        char temp[MAX];
        strcpy(temp, s1);
        strcpy(s1, s2);
        strcpy(s2, temp);
    }
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

    int lenc = max(lena, lenb) + 1;

    for (i = 1; i <= lenc; i++)
    {
        if (a[i] < b[i])
        {
            a[i + 1]--;
            a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }

    if (c[lenc] == 0 && lenc > 0)
    {
        lenc--;
    }

    for (i = lenc; i > 0; i--)
    {
        if (flag)
        {
            printf("-");
            flag = false;
        }
        printf("%d", c[i]);
    }

    printf("\n");
    return 0;
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}

bool compare(char *s1, char *s2) // 如果s1>=s1返回true
{
    int u = strlen(s1);
    int v = strlen(s2);
    if (u != v)
    {
        return u > v;
    }
    for (int i = 0; i < u; i++)
    {
        if (s1[i] != s2[i])
        {
            return s1[i] > s2[i];
        }
    }
    return true;
}