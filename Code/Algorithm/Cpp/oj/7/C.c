#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct score_index
{
    int score[8000];
    int score2[8000];
};

void s_put(int scorew[], int scorel[], int num);

int main(void)
{
    struct score_index score11;
    struct score_index score21;
    int num11 = 0;
    int cntw11 = 0;
    int cntl11 = 0;
    int num21 = 0;
    int cntw21 = 0;
    int cntl21 = 0;

    char ch;

    while ((ch = getchar()) != 'E')
    {
        if (ch == '\n')
        {
            continue;
        }
        if (ch == 'W')
        {
            score11.score[num11]++;
            score21.score[num21]++;
            cntw11++;
            cntw21++;
        }
        if (ch == 'L')
        {
            score11.score2[num11]++;
            score21.score2[num21]++;
            cntl11++;
            cntl21++;
        }
        if ((cntw11 >= 11 || cntl11 >= 11) && (fabs(cntw11 - cntl11) >= 2))
        {
            num11++;
            cntw11 = 0;
            cntl11 = 0;
        }
        if ((cntw21 >= 21 || cntl21 >= 21) && (fabs(cntw21 - cntl21) >= 2))
        {
            num21++;
            cntw21 = 0;
            cntl21 = 0;
        }
    }

    s_put(score11.score, score11.score2, num11);
    printf("\n");
    s_put(score21.score, score21.score2, num21);

    return 0;
}

void s_put(int scorew[], int scorel[], int num)
{
    int i;
    for (i = 0; i <= num; i++)
    {
        printf("%d:%d\n", scorew[i], scorel[i]);
    }
}