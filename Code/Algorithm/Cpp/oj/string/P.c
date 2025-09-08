#include <stdio.h>
#include <string.h>

char ufo[10];
char human[10];

long long multiply(char *str, int len);

int main(void)
{
    scanf("%6s", ufo);
    scanf("%6s", human);

    long long product1 = 0;
    long long product2 = 0;

    int len1 = strlen(ufo);
    int len2 = strlen(human);

    product1 = multiply(ufo, len1);
    product2 = multiply(human, len2);

    if (product1 % 47 == product2 % 47)
    {
        printf("GO\n");
    }
    else
    {
        printf("STAY\n");
    }

    return 0;
}

long long multiply(char *str, int len)
{
    long long product = 1;
    for (int i = 0; i < len; i++)
    {
        product *= (str[i] - '@');
    }
    return product;
}