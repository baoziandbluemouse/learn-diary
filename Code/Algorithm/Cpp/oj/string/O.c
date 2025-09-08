#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char str[1010];
char key[110];

int main(void)
{
    scanf("%100s", key);
    scanf("%1000s", str);
    int i;
    int cnt = 0;

    for (i = 0; i < strlen(key); i++)
    {
        key[i] = tolower(key[i]);
    }

    for (i = 0; i < strlen(str); i++)
    {
        if (isupper(str[i]))
        {
            str[i] = str[i] - (key[cnt] - 'a');
            if (str[i] < 'A')
            {
                str[i] = str[i] + 26;
            }
        }
        else
        {
            str[i] = str[i] - (key[cnt] - 'a');
            if (str[i] < 'a')
            {
                str[i] = str[i] + 26;
            }
        }
        cnt++;
        if (cnt == strlen(key))
        {
            cnt = 0;
        }
    }
    puts(str);

    return 0;
}