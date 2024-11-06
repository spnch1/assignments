#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void getInput(const double *_var) {
    char valid = 0;

    do {
        valid = scanf(" %lf", &*_var);
        fflush(stdin);

        if (!valid || *_var < 0.001 || *_var > 1000) {
            printf("Invalid input. Please try again...\n");
            fflush(stdin);
            valid = 0;
        }

    } while (!valid);
}