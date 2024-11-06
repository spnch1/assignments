#include "functions.h"
#include <stdio.h>
#include <conio.h>
#include <tgmath.h>

double getDouble (const char *string) {
    double value;
    printf("%s", string);

    while (scanf(" %lf", &value) != 1) {
        printf("The input is not a number. Try again!\n");
        fflush(stdin);
        printf("%s", string);
    }

    return value;
}

double getEpsilon() {
    double epsilon;

    do {
        epsilon = getDouble("epsilon - ");

        if (epsilon < 0) {
            printf("Epsilon must be non-negative! Try again!\n");
            fflush(stdin);
        }
    } while (epsilon < 0);

    return epsilon;
}

int getChoice() {
    int choice = 0;

    printf("\nChoose calculation:\n");
    printf("1 - Calculate sine\n");
    printf("2 - Calculate cosine\n");
    printf("Enter your choice (1 or 2):\n");

    do {
        int input = getch();
        if (input == '1') {
            choice = 1;
        } else if (input == '2') {
            choice = 2;
        } else {
            printf("Please enter either 1 or 2.\n\n");
            fflush(stdin);
        }
    } while (choice != 1 && choice != 2);
    return choice;
}

unsigned long long factorial (int n) {
    if (n == 0) return 1;

    unsigned long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

double sin_Taylor (double x, double epsilon) {
    double delta = x;
    double result = x;
    int n = 1;

    while (fabs(delta) > epsilon) {
        delta *= (-x * x) / ((2 * n) * (2 * n + 1));
        result += delta;
        n++;
    }

    return result;
}

double cos_Taylor (double x, double epsilon) {
    double delta = 1;
    double result = 1;
    int n = 1;

    while (fabs(delta) > epsilon) {
        delta *= (-x * x) / (2 * n * (2 * n - 1));
        result += delta;
        n++;
    }

    return result;
}