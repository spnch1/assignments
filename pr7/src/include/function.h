#ifndef FUNCTION_H
#define FUNCTION_H

#define MIN_EPS 1e-15
#define MAX_EPS 1
#define MIN_T (-100.0)
#define MAX_T 100.0
#define MIN_RANGE (-100.0)
#define MAX_RANGE 100.0
#define STEP 1e-3
#define MAX_ITER 1000
#define MAX_ROOTS 1000

// condition.c

unsigned char conditionT(double value);
unsigned char conditionIntervalCos(double value);
unsigned char conditionIntervalSin(double value);
unsigned char conditionEpsilon(double value);

// calculation_data.c

double equationCos(double x, double t);
double equationSin(double x, double t);
double equationDerivativeCos(double x, double t);
double equationDerivativeSin(double x, double t);

// validation.c

double getDouble(char *message, unsigned char (*condition)(double), double min, double max);
unsigned char getChoice(char *message, unsigned char choice1, unsigned char choice2);
unsigned char isRootUnique(double roots[], int count, double newRoot, double epsilon);
unsigned isRootInsideInterval(double x, double a, double b);

// calculation.c

double bisection(double (*f)(double, double), double a, double b, double t, double epsilon);
double newton(double (*f)(double, double), double (*df)(double, double), double a, double t, double epsilon);
void calculate(double (*f)(double, double), double (*df)(double, double), double a, double
b, double t, double epsilon, unsigned char calculationMethod);

// misc.c

void clearScreen();
void pressToExit();

#endif //FUNCTION_H