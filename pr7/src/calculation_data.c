#include "./include/function.h"

#include <tgmath.h>

double equationCos(const double x, const double y) {
    return (cos(y / x) - 2.0 * sin(1.0 / x) + 1.0 / x);
}

double equationSin(double x, double y) {
    return (sin(log(x)) - cos(log(x)) + y * log(x));
}

double equationDerivativeCos(const double x, double y) {
    return ((y * sin(y / x) + 2.0 * cos(1.0 / x) - 1.0) / (x * x));
}

double equationDerivativeSin(double x, double y) {
    return ((sin(log(x)) + cos(log(x)) + y) / x);
}