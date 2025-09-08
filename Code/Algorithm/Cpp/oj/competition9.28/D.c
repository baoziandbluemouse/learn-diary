#include <stdio.h>

int main(void)
{
    int q, p;
    double q1, p1;

    scanf("%d%d", &p, &q);

    q1 = (100 - q) * 0.01;
    p1 = p * 0.01;

    printf("%.4lf", q1 * p1);

    return 0;
}