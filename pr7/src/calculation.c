#include "./include/function.h"
#include "./include/color.h"

#include <stdio.h>
#include <tgmath.h>

double halfDivision(double (*function)(double, double), double a, double b, double t, double epsilon) {
    double delta = 0;
    int iter = 0;
    double x = 0, fa = 0, fx = 0;

    do {
        x = (a + b) / 2.0;
        delta = fabs(b - a);
        fa = function(a, t);
        fx = function(x, t);
        fa * fx > 0
                ? (a = x)
                : (b = x);
        iter++;
        if (iter > MAX_ITER)
            {
            printf(NOTICE_MSG "Maximum iterations outreached. Method did not converge.\n");
            return NAN;
        }
    } while (delta > epsilon);

    return x;
}

double newton(double (*function)(double, double), double (*functionDerivative)(double, double), double a, double t, double epsilon) {
    double x = a;
    double delta;
    int iter = 0;
    do {
        double derivative = functionDerivative(x, t);
        delta = function(x, t) / derivative;
        x -= delta;
        iter++;

        if (iter > MAX_ITER) {
            printf(NOTICE_MSG "Newton's method did not converge within the maximum number of iterations.\n");

            return NAN;
        }
    } while (fabs(delta) > epsilon);

    return x;
}

void calculation(double (*function)(double, double), double (*functionDerivative)(double, double), double a, double b, double t, double epsilon, int method) {
    double left = a;
    int precision = fabs(log10(epsilon));
    int rootsFound = 0;
    double roots[MAX_ROOTS] = {};

    while (left < b) {
        double right = fmin(left + STEP, b);
        double fLeft = function(left, t);
        double fRight = function(right, t);

        if (left <= 0 && right >= 0) {
            left = right;
            continue;
        }

        if (fLeft * fRight <= 0) {
            double x = 0;

            switch (method) {
                case '1':
                    x = halfDivision(function, left, right, t, epsilon);
                    break;
                case '2':
                    x = newton(function, functionDerivative, left, t, epsilon);
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