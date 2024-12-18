#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "function.h"

        // INPUT

int get_int(const char *str, int min, int max) {
    int value = 0, entered_value = 0;

    printf("%s [%d, %d]:\n", str, min, max);
    do {
        entered_value = scanf("%d", &value);

        if (entered_value != 1 || value < min || value > max) {
            printf("Invalid input. Try again...\n");
            fflush(stdin);
        }
        fflush(stdin);
    } while (entered_value != 1 || value < min || value > max);

    return value;
}

double get_epsilon(const char *str, double min, double max) { // MIN AND MAX SHOULD ONLY BE 1, 0.1, 0.01, ...
    double value = 0.0;
    int entered_value = 0;

    printf("%s ", str);
    print_valid_epsilon_values(min, max);

    do {
        entered_value = scanf("%lf", &value);

        if (entered_value != 1 || value < min || value > max || !is_valid_epsilon(value)) {
            printf("Invalid input. Try again...\n");
            fflush(stdin);
        }
        fflush(stdin);
    } while (entered_value != 1 || value < min || value > max || !is_valid_epsilon(value));

    return value;
}

void getSLAE(double **a, double *b, int n) {
    printf("\nEnter the coefficients and constants for the SLAE:");
    for (int i = 0; i < n; i++) {
        printf("\nRow %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            printf("A[%d][%d] = ", i + 1, j + 1);
            while (scanf("%lf", &a[i][j]) != 1) {
                printf("Invalid input. Please enter a number.\n");
                fflush(stdin);
            }
        }
        printf("B[%d] = ", i + 1);
        while (scanf("%lf", &b[i]) != 1) {
            printf("Invalid input. Please enter a number.\n");
            fflush(stdin);
        }
    }
}

        // CALCULATION

void solveSLAE(double **a, double *b, double *x, int n, double epsilon) {
    double *xp = malloc(sizeof(double) * n);
    double prop;
    int iter = 0;

    for (int i = 0; i < n; i++) {
        if (fabs(a[i][i]) < 1e-10) {
            printf("Division by zero or near-zero detected at A[%d][%d]. Please restart the program.\n", i + 1, i + 1);
            free(xp);
            return;
        }
        xp[i] = b[i] / a[i][i];
    }

    do {
        prop = 0.0;
        iter++;

        for (int i = 0; i < n; i++) {
            double sum = 0.0;

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += a[i][j] * xp[j];
                }
            }

            x[i] = (b[i] - sum) / a[i][i];

            double delta = fabs(x[i] - xp[i]);
            if (delta > prop) {
                prop = delta;
            }
        }

        for (int i = 0; i < n; i++) {
            xp[i] = x[i];
        }

    } while (prop > epsilon);

    printf("\nSLAE solved in %d iterations.\n", iter);

    free(xp);
}

        // MISCELLANEOUS

int count_decimal_places(double value) {
    int count = 0;

    while (fabs(value - (int)value) > 0.000000001) {
        value *= 10;
        count++;
    }

    return count;
}

int is_valid_epsilon(double value) {
    if (value <= 0) {
        return 0;
    }
    double result = log10(value);
    return floor(result) == result;
}

void print_valid_epsilon_values(double min, double max) {
    int count = 0;
    double values[100];

    for (double value = min; value <= max; value *= 10) {
        values[count++] = value;
    }

    printf("{");
    if (count <= 4) {
        for (int i = 0; i < count; i++) {
            if (i > 0) printf(", ");
            printf("%g", values[i]);
        }
    } else {
        printf("%g, %g, %g, ..., %g", values[0], values[1], values[2], values[count - 1]);
    }
    printf("}:\n");
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#elifdef __unix__
    system("clear");
#endif
}