#include <stdio.h>
#include <string.h>

#define MAX 10010

int main(void)
{
    int n;
    char str1[MAX];
    char str2[MAX];
    int cnt = 0;

    scanf("%d", &n);

    scanf("%10010s", str1);

    scanf("%10010s", str2);

    for (int i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);

    return 0;
}