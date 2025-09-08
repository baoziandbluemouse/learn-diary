#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x;
    cin>>x;
    if(x == 1 || x == 2 || x == 3){
        cout<<-1<<"\n";
        return;
    }
    else if (x%2 == 0){
        cout<<2<<"\n";
    }
    else{
        cout<<1<<"\n";
    }
}

int main()
{
    int _;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}