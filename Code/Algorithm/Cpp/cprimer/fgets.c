#include <stdio.h>
#define STLEN 14

int main(void)
{
    char words[STLEN];

    puts("print");
    fgets(words, STLEN, stdin);
    printf("(puts(),then fputs())\n");
    puts(words);
    fputs(words, stdout);
    puts("another");
    fgets(words, STLEN, stdin);
    printf("(puts(),then fputs())\n");
    puts(words);
    fputs(words, stdout);
    printf("done");

    return 0;
}