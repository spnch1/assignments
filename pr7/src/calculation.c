#include "./include/function.h"
#include "./include/color.h"

#include <stdio.h>
#include <tgmath.h>

double bisection(double (*f)(double, double), double a, double b, const double y, const double epsilon) {
    double delta = 0;
    int iter = 0;
    double x = 0, fa = 0, fx = 0;

    do {
        x = (a + b) / 2.0;
        delta = fabs(b - a);
        fa = f(a, y);
        fx = f(x, y);
        fa * fx > 0 ? (a = x) : (b = x);
        iter++;

        if (iter > MAX_ITER)
            {
            printf(NOTICE_MSG "Maximum iterations outreached. Method did not converge.\n");
            return NAN;
        }
    } while (delta > epsilon);

    return x;
}

double newton(double (*f)(double, double), double (*df)(double, double), const double a, const double y, double epsilon) {
    double x = a;
    double delta;
    int iter = 0;
    do {
        const double derivative = df(x, y);
        delta = f(x, y) / derivative;
        x -= delta;
        iter++;

        if (iter > MAX_ITER) {
            printf(NOTICE_MSG "Newton's method did not converge within the maximum number of iterations.\n");

            return NAN;
        }
    } while (fabs(delta) > epsilon);

    return x;
}

void calculate(double (*f)(double, double), double (*df)(double, double), const double a, double b,
               const double y, double epsilon, const unsigned char calculationMethod) {
    double left = a;
    const int precision = fabs(log10(epsilon));
    int rootsFound = 0;
    double roots[MAX_ROOTS] = {};

    while (left < b) {
        const double right = fmin(left + STEP, b);
        const double fLeft = f(left, y);
        const double fRight = f(right, y);

        if (left <= 0 && right >= 0) {
            left = right;
            continue;
        }

        if (fLeft * fRight <= 0) {
            double x = 0;

            switch (calculationMethod) {
                case '1':
                    x = bisection(f, left, right, y, epsilon);
                    break;
                case '2':
                    x = newton(f, df, left, y, epsilon);
                    break;
                default:
                    printf(ERR_MSG "Invalid input.\n");
                    break;
            }

            if (isRootUnique(roots, rootsFound, x, epsilon) && isRootInsideInterval(x, a, b) && !isnan(x)) {
                roots[rootsFound] = x;

                printf(GRN"Root x_%03d: x = %.*lf\n"RESET, rootsFound + 1, precision, x);
                rootsFound++;
            }
        }

        left = right;
    }

    if (rootsFound == 0) {
        printf("\n" NOTICE_MSG "No roots found in the given interval.\n");
    }
}