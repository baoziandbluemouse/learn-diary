#include <stdio.h>
#include <string.h>
#define MAX 640
char str[MAX];
int len_index[MAX];
char word_index[MAX][MAX];

int main(void)
{
    int i = 0;
    int len = 0;
    int cnt = 0;
    int max = 0;
    int j = 0;

    fgets(str, MAX, stdin);

    while (str[i] != '\0')
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
        }
        i++;
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ' || str[i] == '.')
        {
            len_index[cnt] = len;
            cnt++;
            len = 0;
        }
        else
        {
            word_index[cnt][len] = str[i];
            len++;
        }
    }

    for (i = 0; i <= cnt; i++)
    {
        if (len_index[i] > max)
        {
            max = len_index[i];
            j = i;
        }
    }

    printf("%s\n", word_index[j]);

    return 0;
}