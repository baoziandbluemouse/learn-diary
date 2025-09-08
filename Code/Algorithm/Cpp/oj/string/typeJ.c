#include <stdio.h>
#include <string.h>
#define MAX 1200
char str[MAX];
int num[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main(void)
{
    int i = 0;
    int j = 0;
    int cnt = 0;
    int increase = 1;
    scanf("%1000s", str);

    while (i <= strlen(str))
    {
        if (str[j] == str[i])
        {
            cnt++;
        }
        if (str[j] != str[i] || i == strlen(str))
        {
            printf("%d%d", cnt, num[str[j] - '0']);
            j = i;
            cnt = 0;
            if (i != strlen(str))
            {
                increase = 0;
            }
        }
        if (increase)
        {
            i++;
        }
        else
        {
            increase = 1;
        }
    }
    printf("\n");
    return 0;
}