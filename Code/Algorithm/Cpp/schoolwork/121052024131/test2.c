#include<stdio.h>
#include<string.h>

char ls[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};

int main(void)
{
	char c;
	printf("please input a capital letter:\n");
	scanf("%c",&c);
	int len = c-'A';
	int i=0;
	int j=0;
	int k=0;
	printf("the output letter pyramid is:\n");
	for(i=0;i<=len;i++)
	{
		for(j=i;j<len;j++)
		{
			printf(" ");
		}
		for(k=len-i;k<len;k++)
		{
			printf("%c",ls[k]);
		}
		printf("%c",c);
		for(k=len-1;k>=len-i;k--)
		{
			printf("%c",ls[k]);
		}
		printf("\n");
	}
	return 0;
}
