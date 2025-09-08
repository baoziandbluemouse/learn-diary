#include <bits/stdc++.h>
using namespace std;
set<int> st;
set<int>::iterator it1, it2, it3;
void solve()
{
    int opt, num;
    cin >> opt >> num;
    if (opt == 1)
    {
        if (!st.insert(num).second)
        {
            cout << "Already Exist" << "\n";
        }
    }
    else if (st.size())
    {
        if (st.find(num) != st.end()) // 找到了
        {
            cout << num << "\n";
            st.erase(num);
        }
        else
        {
            it1 = it2 = it3 = st.lower_bound(num);
            if (it1 == st.begin()) // 特殊情况1 在开头
            {
                cout << *it1 << "\n";
                st.erase(it1);
            }
            else if (it1 == st.end()) // 特殊情况2 在结尾
            {
                it3--;
                cout << *it3 << "\n";
                st.erase(it3);
            }
            else
            {
                it2--;                       // 表示it2是it1的前一个
                if (*it1 - num < num - *it2) // 表示it1更接近num
                {
                    cout << *it1 << "\n";
                    st.erase(it1);
                }
                else
                {
                    cout << *it2 << "\n";
                    st.erase(it2);
                }
            }
        }
    }
    else
    {
        cout << "Empty" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}