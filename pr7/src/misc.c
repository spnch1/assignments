#include "./include/function.h"

#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#elifdef __unix__
    system("clear");
#endif
}

void pressToExit() {
    unsigned short value = 0;
    do {
        value = getch();
        value = tolower(value);

        if (value == 'q') {
            exit(0);
        }
    } while (value != 'q' && value != 13);
}