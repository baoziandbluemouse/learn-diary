#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isprime[120] = {0};
int primenumber[120] = {
    0,
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
};

void init(void)
{
    for (int i = 1; i < 26; i++)
    {
        isprime[primenumber[i]] = 1;
    }
}
int main(void)
{

    init();
    for (int i = 6; i <= 100; i += 2)
    {
        for (int j = 1; j < 26; j++)
        {
            if (isprime[i - primenumber[j]] == 1)
            {
                printf("%d=%d+%d\n", i, primenumber[j], i - primenumber[j]);
                break;
            }
        }
    }
    return 0;
}