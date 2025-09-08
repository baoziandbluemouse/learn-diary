#include <bits/stdc++.h>
using namespace std;

int getcnt(string& s)
{
	int n = s.size();
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	for(int i=0;i<n;i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z')
		{
			flag1 = true;
		}
		if(s[i] >= 'a' && s[i] <= 'z')
		{
			flag2 = true;
		}
		if(s[i] >= '0' && s[i] <= '9')
		{
			flag3 = true;
		}
	}
	if(flag1 && flag2 && flag3)
	{
		return 5;
	}
	else if((flag1 && flag3) || (flag2 && flag3))
	{
		return 3;
	}
	else if(flag1 && flag2)
	{
		return 1;
	}
	return 0;
}


void solve()
{
	string s;
    vector<string> res;
    while (getline(cin, s))
    {
        string t;
        for (int i = 0; i < s.size(); i++)
         {
             if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
             {
                 t += s[i];
             }
             else
             {
                 if (t.size())   res.push_back(t);
                 t = "";
             }
         }
         if (t.size())   res.push_back(t);
    }
	
	int cnt_sum = 0;
	int len = 0;
	int cnt = res.size();
	for(auto &x:res)
	{
		len+=x.size();
		cnt_sum+=getcnt(x);
	}
	cout<<cnt_sum<<"\n";
	cout<<len<<" "<<cnt<<"\n";
}



int main()
{
	int _ = 1;
	//cin>>_;
	while(_--)
	{
		solve();
	}
	return 0;
}
