#include <bits/stdc++.h>
using namespace std;

void work(string preor, string inor)
{
    if (preor.empty())
    {
        return;
    }
    char root = preor[0];       // 前序遍历的第一个节点就是根节点
    int pos = inor.find(root);  // 找到根节点在中序遍历中的下标
    preor.erase(preor.begin()); // 把前序遍历的根节点删除
    string leftpreor = "";
    string rightpreor = "";
    string leftinor = "";
    string rightinor = "";
    if (preor.size() > 0)
    {
        leftpreor = preor.substr(0, pos);
        rightpreor = preor.substr(pos);
    }
    if (inor.size() > 0)
    {
        leftinor = inor.substr(0, pos);
        rightinor = inor.substr(pos + 1);
    }
    work(leftpreor, leftinor);
    work(rightpreor, rightinor);
    cout << root;
}

int main()
{
    string preor, inor;
    cin >> inor >> preor;
    work(preor, inor);
    cout << "\n";
    return 0;
}