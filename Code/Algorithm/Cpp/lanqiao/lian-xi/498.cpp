#include<bits/stdc++.h>
using namespace std;
int mon[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};

string my_string(int n) {
	string s;
	while(n) {
		s= (char)(n%10 + '0') + s;
		n/=10;
	}
	return s;
}



bool ishefa(int x) {
	int year = x/10000;
	int month = (x%10000)/100;
	int day = x%100;
	if(month == 0 || month>12 || day == 0) {
		return false;
	}
	if(month !=2 && day>mon[month]) {
		return false;
	}
	if(month == 2) {
		if(year%400 == 0 || (year%4 == 0 && year%100 != 0)) {
			if(day > 29) {
				return false;
			}
		} else {
			if(day > 28) {
				return false;
			}
		}
	}
	return true;
}

bool ishuiwen(int x) {
	string s = my_string(x);
	int len = s.size();
	for(int i=0,j=len-1; i<j; i++,j--) {
		if(s[i] != s[j]) {
			return false;
		}
	}
	return true;
}

bool isab(int x) {
	if(!ishuiwen(x)){
		return false;
	}
	string s = my_string(x);
	if(s[0]!=s[2] || s[1] != s[3] || s[0] == s[1]) {
		return false;
	}
	return true;
}



int main() {
	bool flag1 = false;
	int n;
	cin>>n;
	for(int i=n+1;; i++) {
		if(ishefa(i)) {
			if(flag1 == false && ishuiwen(i)){
				cout<<i<<"\n";
				flag1 = true;
			}
			if(isab(i)){
				cout<<i<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
