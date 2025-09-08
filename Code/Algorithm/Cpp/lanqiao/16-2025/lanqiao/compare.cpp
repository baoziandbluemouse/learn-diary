#include<bits/stdc++.h>
using namespace std;



int main()
{
	int cnt = 0;
	while(1)
	{
		cnt++;
		system("data.exe > data.in");
		system("my.exe < data.in > my.out");
		system("std.exe < data.in > std.out");
		if(system("fc my.out std.out") == 1)
		{
			system("pause");
		}
	}
	cout<<"Test case:"<<cnt<<"\n";
	return 0;
}
