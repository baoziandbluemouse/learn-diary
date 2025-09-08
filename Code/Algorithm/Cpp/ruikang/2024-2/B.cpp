#include <bits/stdc++.h>
 using namespace std;
 using pii = pair<int, int>;
 int get_score(int x)
 {
     if (x == 1) return 25;
     else if (x == 2)    return 21;
     else if (x == 3)    return 18;
     else if (x == 4)    return 16;
     else
     {
         int res = 16;
         return res - (x - 4);
     }
 }
 
 int main()
 {
     int n;
     cin >> n;
     
     map<int, int> mp;
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= 20; j++)
         {
             int c, p;
             cin >> c >> p;
             mp[c] += get_score(p);
         }
     }
     
     vector<pii> res;
     for (auto [x, y] : mp)
     {
         res.push_back({x, y});
     }
     
     sort(res.begin(), res.end(), [&](pii a, pii b) -> bool{
         if (a.second != b.second)   return a.second > b.second;
         return a.first < b.first;
     });
     
     for (auto x : res)  cout << x.first << " " << x.second << "\n";
     return 0;
 }
