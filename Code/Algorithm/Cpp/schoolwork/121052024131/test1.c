#include <stdio.h>
#include <string.h>
const int N = 110;
char st[110];
char newstr[110]={'0'};
int main()
{
	printf("please input a string:\n");
	scanf("%100s", st);
	int len = strlen(st);
	int cnt = 1;
	int i = 0;
	int j = 0;
	newstr[0] = st[0];
	for (i = 1; i < len; i++)
	{
		int flag = 0;
		for (j = 0; j < cnt; j++)
		{
			if (newstr[j] == st[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			newstr[cnt] = st[i];
			cnt++;
		}
	}
	printf("the output string is:\n");
	printf("%s\n", newstr);
	return 0;
}
