#include <stdio.h>
#include <string.h>
/*Rock，Scissors 和 Paper
 */
#define SIZE 20

int main(void)
{
    int n;
    char str1[SIZE];
    char str2[SIZE];

    scanf("%d", &n);

    int i = 0;

    for (i = 0; i < n; i++)
    {
        scanf("%15s%15s", str1, str2);
        if (str1[0] == str2[0])
        {
            printf("Tie\n");
        }
        else if (str1[0] == 'R')
        {
            if (str2[0] == 'P')
            {
                printf("Player2\n");
            }
            else
            {
                printf("Player1\n");
            }
        }
        else if (str1[0] == 'P')
        {
            if (str2[0] == 'R')
            {
                printf("Player1\n");
            }
            else
            {
                printf("Player2\n");
            }
        }
        else if (str1[0] == 'S')
        {
            if (str2[0] == 'R')
            {
                printf("Player2\n");
            }
            else
            {
                printf("Player1\n");
            }
        }
    }

    return 0;
}
