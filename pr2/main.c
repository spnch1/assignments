#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "./include/functions.h"

int main(void) {
    unsigned DP = 0;
    double a = 0, b = 0, c = 0;
    double P = 0, p = 0, S = 0, ha = 0, hb = 0, hc = 0, ma = 0, mb = 0, mc = 0, ba = 0, bb = 0, bc = 0;
    char choice = 0;

    printf("The program calculates the perimeter, area, heights, medians and bisectors of the given triangle.\n");
    printf("Please enter values of the triangle's sides. The accepted range is [0.001, 1000].\n");

    do {
        a = b = c = 0;
        DP = 0;

         do {
            printf("\n1st value:\n");
            getInput(&a);

            printf("\n2nd value:\n");
            getInput(&b);

            printf("\n3rd value:\n");
            getInput(&c);

            if (a + b <= c || a + c <= b || b + c <= a) {
                printf("\nInvalid input. These sides do not form a triangle. Press press Enter to try again...\n");
                getchar();
            }

        } while (a + b <= c || a + c <= b || b + c <= a);

        printf("\nNow enter the number of decimal points [0,12] for the results:\n");

        while (scanf(" %d", &DP) != 1 || DP > 12) {
            printf("\nInvalid input. Please try again...\n");
            fflush(stdin);
        }

        P = a + b + c;
        p = P / 2.0;

        S = sqrt(p * (p - a) * (p - b) * (p - c));

        ha = 2.0 * S / a;
        hb = 2.0 * S / b;
        hc = 2.0 * S / c;

        ma = sqrt(2.0 * b * b + 2.0 * c * c - a * a ) / 2.0;
        mb = sqrt(2.0 * a * a + 2.0 * c * c - b * b ) / 2.0;
        mc = sqrt(2.0 * a * a + 2.0 * b * b - c * c ) / 2.0;

        ba = 2.0 / (b + c) * sqrt(b * c * p * (p - a));
        bb = 2.0 / (a + c) * sqrt(a * c * p * (p - b));
        bc = 2.0 / (a + b) * sqrt(a * b * p * (p - c));

        printf("\nArea of the triangle: %.*lf", DP, S);
        printf("\nPerimeter of the triangle: %.*lf", DP, P);
        printf("\nHeights drawn to the sides a, b, c respectively: %.*lf, %.*lf, %.*lf", DP, ha, DP, hb, DP, hc);
        printf("\nMedians drawn to the sides a, b, c respectively: %.*lf, %.*lf, %.*lf", DP, ma, DP, mb, DP, mc);
        printf("\nBisectors drawn to the sides a, b, c respectively: %.*lf, %.*lf, %.*lf", DP, ba, DP, bb, DP, bc);

        printf("\n\nRestart the program? [Y/N]\n");

        do {
            choice = tolower(getchar());

            fflush(stdin);

            if (choice != 'y' && choice != 'n') {
                printf("\nInvalid input. Please enter Y or N.\n");
            }

        } while (choice != 'y' && choice != 'n');

        clearScreen();
        printf("\n");

    } while (choice == 'y');

    return 0;
}