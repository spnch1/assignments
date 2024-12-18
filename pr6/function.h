#ifndef FUNCTION_H
#define FUNCTION_H

int get_int(const char *str, int min, int max);
double get_epsilon(const char *str, double min, double max);
void getSLAE(double **a, double *b, int n);

void solveSLAE(double **a, double *b, double *x, int n, double epsilon);

int count_decimal_places(double value);
int is_valid_epsilon(double value);
void print_valid_epsilon_values(double min, double max);
void clear_screen();

#endif