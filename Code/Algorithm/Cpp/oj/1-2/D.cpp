#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define N 150;
char str1[100];
int len;
int record = 0;
double dfs(char *str1, int start);
int main(void)
{
    scanf("%[^\n]", str1);
    len = strlen(str1);
    double result = dfs(str1, 0);
    printf("%.6lf\n", result);
    return 0;
}

double dfs(char *str1, int start)
{
    double a = 0, b = 0, sum = 0;
    bool flag = false;
    bool flag2 = false;
    int j = 0, i = 0;
    for (i = start; i < len; i++)
    {
        if (str1[i] == '+' && str1[i + 1] == ' ')
        {
            a = dfs(str1, i + 2);
            i = record;
            b = dfs(str1, i + 2);
            return a + b;
        }
        else if (str1[i] == '-' && str1[i + 1] == ' ')
        {

            a = dfs(str1, i + 2);
            i = record;
            b = dfs(str1, i + 2);
            return a - b;
        }
        else if (str1[i] == '*' && str1[i + 1] == ' ')
        {

            a = dfs(str1, i + 2);
            i = record;
            b = dfs(str1, i + 2);
            return a * b;
        }
        else if (str1[i] == '/' && str1[i + 1] == ' ')
        {

            a = dfs(str1, i + 2);
            i = record;
            b = dfs(str1, i + 2);
            return a / b;
        }
        if (str1[i] != ' ')
        {
            if (str1[i] == '-')
            {
                flag2 = true;
                continue;
            }
            if (str1[i] == '.')
            {
                flag = true;
                j = i;
            }
            else
            {
                if (flag)
                {
                    sum = sum + (str1[i] - '0') * ((i - j) * 0.1);
                }
                else
                {
                    sum = sum * 10 + (str1[i] - '0');
                }
            }
        }
        else
        {
            break;
        }
    }
    if (flag2)
    {
        sum = -sum;
    }
    record = i - 1;
    return sum;
}
