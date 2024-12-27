#include "./include/function.h"

unsigned char conditionY(const double value) {
    return (value < MIN_Y || value > MAX_Y);
}

unsigned char conditionIntervalCos(const double value) {
    return ((value < MIN_RANGE || value > MAX_RANGE) || value == 0.0);
}

unsigned char conditionIntervalSin(const double value) {
    return (value < 1e-15);
}

unsigned char conditionEpsilon(const double value) {
    return (value < MIN_EPS || value > MAX_EPS);
}