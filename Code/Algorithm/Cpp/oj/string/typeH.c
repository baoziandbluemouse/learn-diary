#include <stdio.h>
#include <string.h>
#define MAX 300
char str1[MAX];
char str2[MAX];
char str1_new[MAX];
char str2_new[MAX];

void solve(const int len1, const int len2, const char *str1, const char *str2, char *str1_new, char *str2_new);

int main(void)
{
    int len1, len2 = 0;
    int len_min, len_max = 0;
    scanf("%200s", str1);
    scanf("%200s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    solve(len1, len2, str1, str2, str1_new, str2_new);

    int cnt = 0;
    int i = 0;

    if (len1 <= len2)
    {
        len_min = strlen(str1_new);
        len_max = strlen(str2_new);

        for (i = 0; i < len_min; i++)
        {
            for (int j = 0; j < len_max; j++)
            {
                if (str1_new[i] == str2_new[j])
                {
                    cnt++;
                    break;
                }
            }
        }
    }
    else
    {
        len_min = strlen(str2_new);
        len_max = strlen(str1_new);

        for (i = 0; i < len_min; i++)
        {
            for (int j = 0; j < len_max; j++)
            {
                if (str2_new[i] == str1_new[j])
                {
                    cnt++;
                    break;
                }
            }
        }
    }

    if (cnt == len_min)
    {
        if (len1 > len2)
        {
            printf("%s is substring of %s\n", str2, str1);
        }
        else
        {
            printf("%s is substring of %s\n", str1, str2);
        }
    }
    else
    {
        printf("No substring\n");
    }
}

void solve(const int len1, const int len2, const char *str1, const char *str2, char *str1_new, char *str2_new)
{
    int i, cnt1 = 0;

    for (i = 0; i < len1; i++)
    {
        if (strchr(str1_new, str1[i]) == NULL)
        {
            str1_new[cnt1] = str1[i];
            cnt1++;
        }
    }
    cnt1 = 0;
    for (i = 0; i < len2; i++)
    {
        if (strchr(str2_new, str2[i]) == NULL)
        {
            str2_new[cnt1] = str2[i];
            cnt1++;
        }
    }
}