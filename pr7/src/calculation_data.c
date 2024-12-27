#include "./include/function.h"

#include <tgmath.h>

double equationCos(double x, double t) {
    return (cos(t / x) - 2.0 * sin(1.0 / x) + 1.0 / x);
}

double equationSin(double x, double t) {
    return (sin(log(x)) - cos(log(x)) + t * log(x));
}

double equationDerivativeCos(double x, double t) {
    return ((t * sin(t / x) + 2.0 * cos(1.0 / x) - 1.0) / (x * x));
}

double equationDerivativeSin(double x, double t) {
    return ((sin(log(x)) + cos(log(x)) + t) / x);
}