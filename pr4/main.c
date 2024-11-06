#include "functions.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>


int main(void) {
    printf("There must've been the explanation of what this program does, but I couldn't put it into words.\n");

    do {
        double x1 = 0, x2 = 0, dx = 0, epsilon = 0;
        int choice = 0;

        x1 = getDouble("\nx1 (deg) - ");
        x2 = getDouble("x2 (deg) - ");
        dx = getDouble("dx (deg) - ");
        epsilon = getEpsilon();


        choice = getChoice();

        x1 = x1 * M_PI / 180.0;
        x2 = x2 * M_PI / 180.0;
        dx = dx * M_PI / 180.0;

        if (choice == 1) {
            printf("\n%15s %15s %15s %15s\n", "x(deg)", "sin(x)", "sin_Taylor", "Difference");
            printf("%15s %15s %15s %15s\n", "===============", "===============", "===============", "===============");

            for (double x = x1; x <= x2; x += dx) {
                double sin_x = sin(x);
                double sin_T = sin_Taylor(x, epsilon);

                printf("%15.4f %15.6f %15.6f %15.6f\n",
                x * 180.0 / M_PI,
                sin_x, sin_T, fabs(sin_x - sin_T));
            }
        }

        if (choice == 2) {
            printf("\n%15s %15s %15s %15s\n", "x(deg)", "cos(x)", "cos_Taylor", "Difference");
            printf("%15s %15s %15s %15s\n", "===============", "===============", "===============", "===============");

            for (double x = x1; x <= x2; x += dx) {
                double cos_x = cos(x);
                double cos_T = cos_Taylor(x, epsilon);

                printf("%15.4f %15.6f %15.6f %15.6f\n",
                x * 180.0 / M_PI,
                cos_x, cos_T, fabs(cos_x - cos_T));
            }
        }

        printf("Press ENTER to restart, any key to exit...\n");
    } while (getch() == 13);

    return 0;
}