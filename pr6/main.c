#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "function.h"

        // WIP

int main(void) {
    printf("=== SLAE solver ===\n");

    do {
        int n = get_int("\nEnter the SLAE size (number of equations)", 2, 10);
        double epsilon = get_epsilon("\nEnter the root calculation accuracy", 1e-10, 1.0);

        double **a = malloc(n * sizeof(double *));

        for (int i = 0; i < n; i++) {
            a[i] = (double *)malloc(n * sizeof(double));
        }

        double *b = malloc(n * sizeof(double));
        double *x = malloc(n * sizeof(double));

        getSLAE(a, b, n);
        solveSLAE(a, b, x, n, epsilon);

        printf("\nSolution:\n");
        for (int i = 0; i < n; i++) {
            printf("x[%d] = %g\n", i + 1, x[i]);
        }

        for (int i = 0; i < n; i++) {
            free(a[i]);
        }
        free(a);
        free(b);
        free(x);

        printf("Press Enter to restart, any key to exit...");
    } while (getch() == 13 && (clear_screen(), 1));
    return 0;
}