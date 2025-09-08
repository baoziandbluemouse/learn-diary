#include <stdio.h>
#include <string.h>
#define MAX 120
char str[MAX];

int main(void)
{
    int i;
    scanf("%100s", str);
    for (i = 0; i <= strlen(str) / 2; i++)
    {
        if (str[i] != str[strlen(str) - 1 - i])
        {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}