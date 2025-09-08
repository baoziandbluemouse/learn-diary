#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double isarc(double x);

int main(void)
{
    double arc = 0.0;

    arc = isarc(1.0 / sqrt(3));

    printf("%.10lf\n", 6 * arc);

    return 0;
}

double isarc(double x)
{
    double arctan = 0.0;
    double arc_sum = 0.0;
    bool flag = false;
    int i = 0;
    for (int k = 1;; k += 2)
    {
        arctan = pow(-1.0, i) * pow(x, k) / k;
        if (fabs(arctan) < 2e-6)
        {
            flag = true;
        }
        arc_sum += arctan;
        if (flag == true)
        {
            return arc_sum;
        }
        i++;
    }
}