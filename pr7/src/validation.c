#include "./include/function.h"
#include "./include/color.h"

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <tgmath.h>

double getDouble(char *string, unsigned char (*condition)(double), const double min, const double max) {
    double value = 0;
    int validInput = 0;
    do {
        printf("%s " BBLK "[%g, %g]\n" CRESET, string, min, max);

        printf(BYEL);
        validInput = scanf("%lf", &value);
        printf(CRESET);

        if (validInput != 1 || condition(value)) {
            printf(ERR_MSG "Invalid input. Press Enter to try again, Q to exit...\n");
            pressToExit();
        }
        fflush(stdin);
    } while (validInput != 1 || condition(value));

    return value;
}

unsigned char getChoice(char *string, const unsigned char choice1, const unsigned char choice2) {
    unsigned char value = 0;
    do {
        printf("%s", string);

        value = getch();
        value = tolower(value);
        if (value != choice1 && value != choice2) {
            printf("\n" ERR_MSG "Invalid choice. Press Enter to try again, Q to exit...\n");
            pressToExit();
        }
    } while (value != choice1 && value != choice2);

    return value;
}

unsigned char isRootUnique(double roots[], const int count, const double newRoot, double epsilon) {
    for (int i = 0; i < count; i++) {
        if (fabs(roots[i] - newRoot) < epsilon) {
            return 0;
        }
    }
    return 1;
}

unsigned isRootInsideInterval(const double x, const double a, const double b) {
    if (x < a || x > b) {
        printf(ERR_MSG "Root is outside the given interval.\n");
        return 0;
    }
    return 1;
}