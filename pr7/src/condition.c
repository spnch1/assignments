#include "./include/function.h"

unsigned char conditionT(double value) {
    return (value < MIN_T || value > MAX_T);
}

unsigned char conditionIntervalCos(double value) {
    return ((value < MIN_RANGE || value > MAX_RANGE) || value == 0.0);
}

unsigned char conditionIntervalSin(double value) {
    return (value < 1e-15);
}

unsigned char conditionEpsilon(double value) {
    return (value < MIN_EPS || value > MAX_EPS);
}