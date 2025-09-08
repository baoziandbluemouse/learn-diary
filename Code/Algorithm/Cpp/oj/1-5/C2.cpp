#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
int number[101], i = 0, p = 1;
char symbol[101], s[256], t[256];
void push() // 算符入栈运算
{
    symbol[++p] = s[i];
}
void pop() // 运算符栈顶元素出栈,并取出操作数栈元素完成相应的运算
{
    switch (symbol[p--]) // 运算完成之后扔掉运算符,也标志着需要运算的数已经运算完成
    {
    case '+':
    {
        number[p] += number[p + 1];
        break;
    }
    case '-':
    {
        number[p] -= number[p + 1];
        break;
    }
    case '*':
    {
        number[p] *= number[p + 1];
        break;
    }
    case '/':
    {
        number[p] /= number[p + 1];
        break;
    }
    case '^':
    {
        number[p] = pow(number[p], number[p + 1]);
    }
    }
}
bool can() // 判断运算符的优先级别,建立标志函数,能否进行运算
{
    if ((s[i] == '+' || s[i] == '-') && symbol[p] != '(') // 在括号之内
        return 1;
    if ((s[i] == '*' || s[i] == '/') && (symbol[p] == '*' || symbol[p] == '/'))
        // 若遇到乘除且p对应的恰好是乘除
        return 1;
    return 0;
}
bool judge(char s[256])
{
    int top = 0, i = 0;
    while (s[i] != '@')
    {
        if (s[i] == '(')
            top++;
        if (s[i] == ')')
        {
            if (top > 0)
                top--;
            else
                return 0;
        }
        i++;
    }
    if (top != 0)
        return 0; // 检测栈是否为空。不空则说明有未匹配的括号
    else
        return 1;
}
int main()
{
    gets(s);
    if (judge(s) == 0)
    {
        cout << "NO";
        return 0;
    }

    s[strlen(s)] = ')';
    symbol[p] = '(';
    while (i < strlen(s))
    {
        while (s[i] == '(') // 左括号处理,压入左括号,有了左括号才能进行与右括号的匹配 while (symbol[p]!='(')
        {
            push();
            i++;
        }
        int x = 0;
        while (s[i] >= '0' && s[i] <= '9') // 取数入操作数栈
            x = x * 10 + s[i++] - '0';
        number[p] = x;
        do
        {
            if (s[i] == ')') // 当右括号后面还有右括号时处理
            {
                while (symbol[p] != '(')
                    pop();                   // 当括号内还有算式没有算完时进行运算
                number[--p] = number[p + 1]; // 当运算完成以后左括号已经没有意义，所以将指针p移向前一个运算符，并复制所得的结果
            }
            else
            { // 根据标志函数值作运算符入栈或出栈运算处理
                while (can())
                    pop(); // 当可以进行运算时运算，然后压入一个运算符
                push();
            }
            i++;
        } while (i < strlen(s) && s[i - 1] == ')'); // 当检测到右括号时，可以运算括号内的内容
    }
    printf("Result=%d", number[0]); // 因为所有的运算全部是建立在括号之内的，所以随着运算符的减少（运算符减少同时标志着需要操作的数减少）和最后的p--，结果一定保存在number[0]内
    return 0;
}