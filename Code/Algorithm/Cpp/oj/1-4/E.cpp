#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int ans = 0;
double a, b, c, d;

double f(double x);
void merge(double l, double r);

int main(void)
{
    scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
    for (double i = -10.0; i <= 10.0; i++)
    {
        double x1 = f(i);
        double x2 = f(i + 1);
        if (x1 * x2 < 0)
        {
            merge(i, i + 1);
            ans++;
        }
        else if (x1 == 0)
        {
            printf("%.2lf ", i);
            ans++;
        }
        if (ans == 3)
        {
            break;
        }
    }
    return 0;
}
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

void merge(double l, double r)
{
    while ((r - l) >= 0.001)
    {
        double mid = (l + r) / 2;
        if (f(mid) * f(r) <= 0)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    printf("%.2lf ", r);
}
