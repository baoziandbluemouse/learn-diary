#include <stdio.h>
#include <string.h>
#define MAX 300

int main(void)
{
    char dna[MAX];

    scanf("%255s", dna);

    for (int i = 0; i < strlen(dna); i++)
    {
        if (dna[i] == 'A')
        {
            printf("T");
            continue;
        }
        if (dna[i] == 'T')
        {
            printf("A");
            continue;
        }
        if (dna[i] == 'C')
        {
            printf("G");
            continue;
        }
        if (dna[i] == 'G')
        {
            printf("C");
            continue;
        }
    }

    printf("\n");

    return 0;
}