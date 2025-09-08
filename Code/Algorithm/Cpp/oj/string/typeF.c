#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 40

int main(void)
{
    char str[MAX];
    int n;
    int first = 1;
    scanf("%d", &n);

    while (getchar() != '\n')
    {
        continue;
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%20s", str);
        for (int j = 1; j < strlen(str); j++)
        {
            if (first)
            {
                if (isalnum(str[0]))
                {
                    printf("%c", toupper(str[0]));
                }
                else
                {
                    printf("%c", str[0]);
                }
                first = 0;
            }
            if (isalnum(str[j]))
            {
                printf("%c", tolower(str[j]));
            }
            else
            {
                printf("%c", str[j]);
            }
        }
        first = 1;
        printf("\n");
    }

    return 0;
}